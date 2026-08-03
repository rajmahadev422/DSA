class Solution {
public:
    vector<int> dp;

    int solve(int idx, vector<int>& sv) {
        int n = sv.size();

        if (idx >= n)
            return 0;

        if (dp[idx] != INT_MIN)
            return dp[idx];

        int s = 0;
        int ans = INT_MIN;

        for (int i = 0; i < 3 && idx + i < n; i++) {
            s += sv[idx + i];
            ans = max(ans, s - solve(idx + i + 1, sv));
        }

        return dp[idx] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};