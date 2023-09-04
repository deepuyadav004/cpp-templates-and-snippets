
class DSU {
    public:
    
    int n;
    vector<int>parent, sz;
    DSU(int x){
        n = x;
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool merge(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return false;
        if(sz[u] > sz[v]){
            parent[v] = u;
            sz[u] += sz[v];
            sz[v] = 0;
        }else{
            parent[u] = v;
            sz[v] += sz[u];
            sz[u] = 0;
        }
        return true;
    }

    int findSize(int node){
        node = findParent(node);
        return sz[node];
    }

    bool isSame(int u, int v){
        return (findParent(u) == findParent(v));
    }
};
