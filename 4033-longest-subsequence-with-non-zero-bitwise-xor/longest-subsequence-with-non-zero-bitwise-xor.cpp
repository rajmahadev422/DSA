class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        int cnt = 0, x = 0;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == 0) cnt++;
            x = x ^ nums[i];
        }
        if(x != 0) return nums.size();
        if(cnt == nums.size()) return 0;
        
        return nums.size() - 1;
    }
};