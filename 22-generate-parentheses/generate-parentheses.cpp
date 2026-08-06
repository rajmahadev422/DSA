class Solution {
public:
    void solve(int l, int r, vector<string> &ans, string curr) {
        if (l < 0 || r < 0 || l > r) return;

        if (l == 0 && r == 0) {
            ans.push_back(curr);
            return;
        }

        solve(l - 1, r, ans, curr + "(");
        solve(l, r - 1, ans, curr + ")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, ans, "");
        return ans;
    }
};