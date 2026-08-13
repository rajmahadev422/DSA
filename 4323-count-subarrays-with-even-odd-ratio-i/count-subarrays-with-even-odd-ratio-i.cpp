class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size(), ans = 0;
        
        for(int i = 0;i < n;i++) {
            int cnto = 0, cnte = 0;
            for(int j = i;j < n;j++) {
                if(nums[j] % 2 == 0) cnte++;
                else cnto++;

                if(cnto != 0 and (1.00*cnte / cnto <= 1.00*a/b)) ans++; 
            }
        }
        return ans;
    }
};