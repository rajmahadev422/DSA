class Solution {
public:
    int score(vector<int> &v, int l, int r, int a, int b, bool turn, vector<vector<int>> &dp) {
        if(l > r) return (a > b) ? 1 : 2;

        if(dp[l][r] != 0) return dp[l][r];

        if(turn) {
            return dp[l][r] = min(score(v, l+1, r, a + v[l], b, !turn, dp), score(v, l, r - 1, a + v[r], b, !turn, dp));
        }
        return dp[l][r] = min(score(v, l+1, r, a, b + v[l], !turn, dp), score(v, l, r - 1, a, b + v[r], !turn, dp));
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int> (piles.size(), 0));
        return score(piles, 0, piles.size()-1, 0, 0, true, dp) == 1;
    }
};