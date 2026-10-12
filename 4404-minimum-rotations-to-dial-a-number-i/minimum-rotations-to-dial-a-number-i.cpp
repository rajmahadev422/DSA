class Solution {
public:
    int minRotations(string s) {
        int prev = 0, ans = 0;

        for(char ele: s) {
            int n = ele - '0';
            ans += min(abs(n - prev), 10 - abs(n - prev));
            prev = n;
        }
        return ans;
    }
};