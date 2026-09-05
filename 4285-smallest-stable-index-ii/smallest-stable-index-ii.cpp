class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), l = INT_MIN, r = INT_MAX;
        vector<int> mx(n), mn(n);

        for(int i = 0;i < n;i++) {
            mx[i] = l = max(l, nums[i]);
        }

        for(int i = n - 1;i >= 0;i--) mn[i] = r = min(r, nums[i]);
        

        for(int i = 0;i < n;i++) {
            if(mx[i] - mn[i] <= k) return i;
        }
        return -1;
    }
};