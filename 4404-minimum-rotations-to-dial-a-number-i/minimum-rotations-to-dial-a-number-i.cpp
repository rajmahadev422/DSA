class Solution {
public:
    int minRotations(string s) {
        int prev = 0, ans = 0;

        for(char ele: s) {
            int n = ele - '0';
            int t = min(abs(n - prev), 10 - abs(n - prev));
            cout<<t<<" ";
            ans += t;
            prev = n;
        }
        return ans;
    }
};