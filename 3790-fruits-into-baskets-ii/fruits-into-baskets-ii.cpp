class Solution {
public:
    vector<int> tree;

    void build(int s, int e, int node, vector<int> &v) {
        if(s == e) {
            tree[node] = v[s];
            return;
        };

        int mid = (s + e) / 2;

        build(s, mid, 2*node + 1, v);
        build(mid + 1, e, 2*node + 2, v);

        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }

    void update(int s, int e, int node, int val) {
        if(s == e) {
            tree[node] = INT_MIN;
            return;
        };
        int mid = (s + e) / 2;

        if(tree[2*node + 1] >= val) update(s, mid, 2*node + 1, val);
        else update(mid + 1, e, 2*node + 2, val);

        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        tree.resize(4*n);

        build(0, n - 1, 0, baskets);
        int ans = 0;
        for(int i = 0;i < fruits.size();i++) {
            int val = fruits[i];

            if(tree[0] >= val) update(0, n-1, 0, val);
            else ans++;
        }
        return ans;
    }
};