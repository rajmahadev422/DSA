class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        int j = 0;
        for(int i = 0;i < nums.size();i++) {
            m[nums[i]]++;
            if(m[nums[i]] <= 2) {
                nums[j] = nums[i];
                j++;
            }
        }

        nums.erase(nums.begin()+j, nums.end());

        return j;
    }
};