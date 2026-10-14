class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;
        for(int i = 0;i < 26;i++) {
            mp[i+'a'] = 26 - i;
        }

        int ans = 0;

        for(int i = 0;i < s.length();i++) ans += mp[s[i]] * (i + 1);
        return ans;
    }
};