class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> m;

        for(int i = 0;i < nums.size();i++) m[nums[i]] = true;
        int i = 1;
        while(true) {
            if(!m.contains(k * i)) return k * i;
            i++;
        }
        return 0;
    }
};