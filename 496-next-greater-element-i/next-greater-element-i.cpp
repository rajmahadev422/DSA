class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for(int i = 0;i < nums2.size();i++) mp[nums2[i]] = i;

        vector<int> ans(nums1.size());
        int k = 0;
        for(int ele:nums1) {
            int idx = mp[ele];
            int x = -1;
            for(int i = idx + 1;i < nums2.size();i++) {
                if(nums2[i] > ele) {
                    x = nums2[i];
                    break;
                }
            }
            ans[k] = x;
            k++;
        }
        return ans;
    }
};