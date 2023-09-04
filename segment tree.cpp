
class SegTree {
    public:
    vector<ll>seg;

    SegTree(int n){
        seg.resize(4*n+5);
    }

    void build(int node, int st, int en, vector<int>&v){
        if(st == en){
            seg[node]=v[st];
            return;
        }

        int mid = (st+en)/2;
        build(2*node, st, mid, v);
        build(2*node+1, mid+1, en, v);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }

    ll query(int node, int st, int en, int l, int r){
        if(st > r || l>en) return -1;
        if(l<=st && en<=r) return seg[node];

        int mid = (st+en)/2;
        return max(query(2*node, st, mid, l, r), query(2*node+1, mid+1, en, l, r));
    }

    void update(int node, int st, int en, int i, int val, vector<int>&v){
        if(st == en){
            v[i]=val;
            seg[node] = val;
            return;
        }

        int mid = (st+en)/2;
        if(i<=mid){
            update(2*node, st, mid, i, val, v);
        }else{
            update(2*node+1, mid+1, en, i, val, v);
        }
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }
};
