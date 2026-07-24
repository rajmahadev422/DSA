class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();

        for(int i = 0;i < n;i++) s.insert(nums[i]);

        for(int i = 0;i < n - 2;i++) {
            for(int j = i + 1;j < n - 1;j++) {
                for(int k = j + 1;k < n;k++) {
                    s.insert(nums[i] ^ nums[j] ^ nums[k]);
                    if(s.size() == 2048) return 2048;
                }
            }
        }
        return s.size();
    }
};