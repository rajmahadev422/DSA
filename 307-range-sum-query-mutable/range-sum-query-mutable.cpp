class NumArray {
public:
    vector<int> tree;
    int end;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4*n);
        this->end = n - 1;
        build(0, n-1, 0, nums);
    };
    
    void build(int s, int e, int node, vector<int> &v) {
        if(s == e) {
            tree[node] = v[s];
            return;
        };

        int mid = (s + e) / 2;

        build(s, mid, 2*node + 1, v);
        build(mid + 1, e, 2*node + 2, v);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    };
    void update(int s, int e, int node, int idx, int val) {
        if(s == e) {
            tree[node] = val;
            return;
        };

        int mid = (s + e)/2;
        if(idx <= mid) update(s, mid, 2*node + 1, idx, val);
        else update(mid + 1, e, 2*node + 2, idx, val);

        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    void update(int index, int val) {
        update(0, this->end, 0, index, val);
    }
    
    int query(int s, int e, int node, int l, int r) {
        if(r < s or e < l) return 0;

        if(l <= s and r >= e) return tree[node];

        int mid = (s + e) / 2;

        int q1 = query(s, mid, 2*node + 1, l, r);
        int q2 = query(mid + 1, e, 2*node + 2, l, r);
        return q1 + q2;
    };

    int sumRange(int left, int right) {
        return query(0, this->end, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */