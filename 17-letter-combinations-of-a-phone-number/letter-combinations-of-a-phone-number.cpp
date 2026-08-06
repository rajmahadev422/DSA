class Solution {
public:
    vector<string> v = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };
    void solve(int idx, string str, vector<string> &ans, string curr){
        if(idx >= str.length()) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0;i < v[str[idx] - '2'].length();i++) {
            solve(idx + 1, str, ans, curr + v[str[idx] - '2'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        solve(0, digits, ans, "");
        return ans;
    }
};