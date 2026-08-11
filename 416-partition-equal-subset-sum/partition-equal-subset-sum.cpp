class Solution {
public:
    vector<vector<int>> dp;

    bool find(vector<int>& v, int t, int idx) {
        if (t == 0)
            return true;
        if (idx >= v.size() || t < 0)
            return false;

        if (dp[idx][t] != -1)
            return dp[idx][t];

        return dp[idx][t] = find(v, t - v[idx], idx + 1) or find(v, t, idx + 1);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return find(nums, target, 0);
    }
};