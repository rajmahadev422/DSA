class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, j = 1;

        unordered_map<char, int> mp;
        mp[s[0]]++;
        int ans = 0;
        while(j < s.length()) {
            mp[s[j]]++;
            while(mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        // ans = max(ans, j - i);
        return ans;
    }
};