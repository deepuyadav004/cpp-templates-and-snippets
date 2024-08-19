template<typename t1, typename t2>
class SegmentTree {
    public:
    vector<t1>seg;

    SegmentTree(int n){
        seg.resize(4*n+10);
    }

    void build(int node, int l, int r, vector<t2>&v){
        if(l == r){
            seg[node] = v[l];
            return;
        }

        int mid = (l+r)/2;
        build(2*node, l, mid, v);
        build(2*node+1, mid+1, r, v);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }

    t1 query(int node, int qStart, int qEnd, int l, int r){
        if(qStart<=l && r<=qEnd){
            return seg[node];
        }

        if(r < qStart || qEnd < l){
            return -1;
        }

        int mid = (l+r)/2;
        return max(query(2*node, qStart, qEnd, l, mid), query(2*node+1, qStart, qEnd, mid+1, r));
    }

    void update(int node, int idx, int l, int r, t2 val, vector<t2>&v){
        if(l == r){
            v[idx]=val;
            seg[node]=val;
            return;
        }

        int mid=(l+r)/2;
        if(idx <= mid){
            update(2*node, idx, l, mid, val, v);
        }else{
            update(2*node+1, idx, mid+1, r, val, v);
        }
        max(seg[2*node], seg[2*node+1]);
    }
};
