class Solution {
public:
    long long countCommas(long long n) {
        long long c = 0;
        long long a1 = 1e3 - 1, a2 = 1e6 - 1, a3 = 1e9 - 1, a4 = 1e12 - 1, a5 = 1e15 - 1;

        return (max(c, (n - a5)*5) + max(c, (min(n, a5) - a4)*4) + max(c, (min(n, a4) - a3)*3) + max(c, (min(n, a3) - a2)*2) + max(c, (min(n, a2) - a1)));
    }
};