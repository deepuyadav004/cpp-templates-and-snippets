class BinaryLifting{
    public:
    vector<vector<int>>dp;
    vector<int>level;

    BinaryLifting(int n){
        dp.resize(n+1, vector<int>(30, -1));
        level.resize(n+1);
    }

    void calcLevel(int node, int par, int l, vector<vector<int>>&gr){
        level[node]=l;
        for(auto it : gr[node]){
            if(it == par) continue;
            calcLevel(it, node, l+1, gr);
        }
    }

    void build(int node, int par, vector<vector<int>>&gr){
        dp[node][0]=par;
        for(int i=1; i<30; i++){
            if(dp[node][i-1] != -1){
                dp[node][i] = dp[dp[node][i-1]][i-1];
            }else{
                dp[node][i] = -1;
            }
        }

        for(auto &it : gr[node]){
            if(it == par) continue;
            build(it, node, gr);
        }
    }

    int lift(int node, int jump){
        if(node == -1 || jump == 0) return node;

        for(int i=29; i>=0; i--){
            if(jump&(1<<i)){
                return lift(dp[node][i], jump-(1<<i));
            }
        }
        return -1;
    }

    int query(int u, int v){
        
        if(level[v] > level[u]) swap(u, v);

        u = lift(u, level[u]-level[v]);
        if(u==v){
            return u;
        }

        for(int i=19; i>=0; i--){
            if(dp[u][i] != dp[v][i]){
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    }
};
