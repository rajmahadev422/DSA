class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long a1 = 1e3 - 1, a2 = 1e6 - 1, a3 = 1e9 - 1, a4 = 1e12 - 1, a5 = 1e15 - 1;

        if(n > a5) {
            ans = (n - a5)*5 + (a5 - a4)*4 + (a4 - a3)*3 + (a3 - a2)*2 + (a2 - a1);
        }
        else if(n > a4) {
            ans = (n - a4)*4 + (a4 - a3)*3 + (a3 - a2)*2 + (a2 - a1);
        }
        else if(n > a3) {
            ans = (n - a3)*3 + (a3 - a2)*2 + (a2 - a1);
        }
        else if(n > a2) {
            ans = (n - a2)*2 + (a2 - a1);
        }
        else if(n > a1) {
            ans = n - a1;
        }
        else ans = 0;

        return ans;
    }
};