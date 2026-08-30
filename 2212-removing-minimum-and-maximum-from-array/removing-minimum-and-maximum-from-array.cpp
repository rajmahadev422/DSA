class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mxi = 0, mn = INT_MAX, mni = 0;

        for(int i = 0;i < n;i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                mxi = i;
            }

            if(mn > nums[i]) {
                mn = nums[i];
                mni = i;
            }
        }
        return min({max(mni, mxi) + 1, min(mxi, mni) + 1 + n - max(mxi, mni), max(n - mxi, n - mni)});
    }
};