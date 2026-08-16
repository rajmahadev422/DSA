class Solution {
public:

    int mySqrt(int x) {
        x = (unsigned long long) x;
        if(x <= 1) return x;
        for(unsigned long long i = 1;i <= x;i++) {
            if(i*i > x) return i - 1;
        }
        return -1;
    }
};