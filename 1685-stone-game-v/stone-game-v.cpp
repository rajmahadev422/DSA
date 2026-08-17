class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;

    int solve(int i, int j) {
        if (j - i <= 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k < j - 1; k++) {

            int left = pref[k + 1] - pref[i];
            int right = pref[j] - pref[k + 1];

            if (left < right) {
                ans = max(ans, left + solve(i, k + 1));
            }
            else if (left > right) {
                ans = max(ans, right + solve(k + 1, j));
            }
            else {
                ans = max(ans,
                    left + max(
                        solve(i, k + 1),
                        solve(k + 1, j)
                    )
                );
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        pref.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(0, n);
    }
};