class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int i = 0, j = 1, n = nums.size(), ans = 0;
        mp[nums[0]]++;
        while (i < n and j < n) {
            while (!mp.empty() and mp[nums[j]] + 1 > k) {
                mp[nums[i]]--;
                i++;
            }
            mp[nums[j]]++;
            j++;
            ans = max(ans, j - i);
        }
        ans = max(ans, j - i);
        return ans;
    }
};