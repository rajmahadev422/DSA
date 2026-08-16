class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> v = { "qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, bool> f;
        unordered_map<char, bool> s;
        unordered_map<char, bool> t;

        for(char c:v[0]) f[c] = true;
        for(char c:v[1]) s[c] = true;
        for(char c:v[2]) t[c] = true;
        
        vector<string> ans;

        for(string word:words) {
            bool flag1 = true, flag2 = true, flag3 = true;
            for(char c:word) {
                c = tolower(c);
                if(!f.contains(c)) {
                    flag1 = false;
                }
                if(!s.contains(c)) flag2 = false;
                if(!t.contains(c)) flag3 = false;
            }
            if(flag1 or flag2 or flag3) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};