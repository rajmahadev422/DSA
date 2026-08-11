class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, bool> mp;

        int prev = nums[0], sum = prev, flag = true;
        mp[prev] = true;
        for(int i = 1;i < nums.size();i++) {
            if(flag and nums[i] - 1 == prev) sum += nums[i];
            else flag = false;

            if(nums[i] == sum) sum++;
            prev = nums[i];
            mp[prev] = true;
        }
        
        while(mp.contains(sum)) sum++;
        return sum;
    }
};