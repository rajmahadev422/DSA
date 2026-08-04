class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;

        string s = to_string(abs((long long)x));
        std::reverse(s.begin(), s.end());

        long long val = stoll(s);

        if (neg) val = -val;

        if (val > INT_MAX || val < INT_MIN)
            return 0;

        return (int)val;
    }
};