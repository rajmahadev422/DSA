class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > 9*n) return -1;

        string ans = "";
        while(s > 0) {
            if(s >= 9) {
                s -= 9;
                ans += "9";
            }
            else {
                ans += to_string(s);
                s = 0;
            }
        }

        if(ans.length() < n) {
            for(int i = ans.length();i < n;i++) ans += "0";
        }
        return stoi(ans);
    }
};