class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int idx, int m, vector<int>& piles) {
        int n = piles.size();

        if (idx >= n)
            return 0;

        if (dp[idx][m] != INT_MIN)
            return dp[idx][m];

        int ans = INT_MIN;

        int sum = 0;

        for (int x = 1; x <= 2 * m && idx + x <= n; x++) {
            sum += piles[idx + x - 1];

            int next = solve(idx + x, max(m, x), piles);

            ans = max(ans, sum - next);
        }

        return dp[idx][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        dp.assign(n, vector<int>(n + 1, INT_MIN));

        int diff = solve(0, 1, piles);

        int total = accumulate(piles.begin(), piles.end(), 0);

        return (total + diff) / 2;
    }
};