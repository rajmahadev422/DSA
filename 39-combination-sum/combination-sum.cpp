class Solution {
public:
    void solve(int idx, int t, vector<int> &c, vector<int> curr, vector<vector<int>> &ans) {
        if(t == 0) {
            ans.push_back(curr);
            return;
        }
        if(idx == c.size() or t < 0) return;

        curr.push_back(c[idx]);
        solve(idx, t - c[idx], c, curr, ans);
        curr.pop_back();
        solve(idx + 1, t, c, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(candidates[0]);
        solve(0, target - candidates[0], candidates, curr, ans);
        curr.pop_back();
        solve(1, target, candidates, curr, ans);
        return ans;
    }
};