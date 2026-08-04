class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, bool> m;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0;i < nums.size();i++) {
            m[nums[i]] = true;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }

        vector<int> ans;

        for(int i = mn;i <= mx;i++) {
            if(m.contains(i)) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};