class Solution {
public:
    struct Node {
        char leftChar;
        char rightChar;
        int leftCount;
        int rightCount;
        int best;
        int size;

        Node() {
            leftChar = rightChar = '#';
            leftCount = rightCount = best = size = 0;
        }
    };

    vector<Node> tree;

    Node comb(Node a, Node b) {

        if (a.size == 0)
            return b;
        if (b.size == 0)
            return a;

        Node res;
        res.size = a.size + b.size;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.leftCount = a.leftCount;
        res.rightCount = b.rightCount;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.rightCount + b.leftCount);

            if (a.leftCount == a.size) {
                res.leftCount = a.size + b.leftCount;
            }

            if (b.rightCount == b.size) {
                res.rightCount = b.size + a.rightCount;
            }
        }

        return res;
    }

    void build(int node, int s, int e, string& str) {
        if (s == e) {
            tree[node].leftChar = str[s];
            tree[node].rightChar = str[s];
            tree[node].leftCount = 1;
            tree[node].rightCount = 1;
            tree[node].best = 1;
            tree[node].size = 1;
            return;
        }

        int mid = s + (e - s) / 2;
        build(2 * node + 1, s, mid, str);
        build(2 * node + 2, mid + 1, e, str);

        tree[node] = comb(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int s, int e, int idx, char val) {
        if (s == e) {
            tree[node].leftChar = val;
            tree[node].rightChar = val;
            tree[node].leftCount = 1;
            tree[node].rightCount = 1;
            tree[node].best = 1;
            tree[node].size = 1;
            return;
        }

        int mid = s + (e - s) / 2;
        if (idx <= mid)
            update(2 * node + 1, s, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, e, idx, val);

        tree[node] = comb(tree[2 * node + 1], tree[2 * node + 2]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, s);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[0].best);
        }

        return ans;
    }
};