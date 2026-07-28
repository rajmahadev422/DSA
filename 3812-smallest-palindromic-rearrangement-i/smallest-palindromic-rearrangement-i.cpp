class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);

        for(char c:s) v[c - 'a']++;
        string ans = "";
        char m = '0';

        for(int i = 0;i < 26;i++) {
            for(int j = 0;j < v[i] / 2;j++) {
                ans += (char)(i + 'a');
            }
            if(v[i] % 2) m = (char)(i + 'a');
        }

        string str = ans;
        reverse(str.begin(), str.end());
        if(m != '0') return ans + m + str;
        return ans + str;
    }
};