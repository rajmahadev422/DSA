class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int> > mp;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto ele:mp) {
            bool f = true;
            for(int i = 0;i < ele.second.size() - 1;i++) {
                if(ele.second[i+1] - ele.second[i] != 1) {
                    f = false;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};