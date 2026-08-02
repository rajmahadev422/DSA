class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                long long temp = ((long long)nums[i]*(long long)nums[j]) / pow(gcd((long long)nums[i], (long long)nums[j]), 2);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};