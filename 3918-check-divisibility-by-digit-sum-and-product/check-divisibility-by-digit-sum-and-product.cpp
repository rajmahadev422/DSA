class Solution {
public:
    bool checkDivisibility(int n) {
        string num = to_string(n);

        int p = 1, s = 0;

        for(int i = 0;i < num.size();i++) {
            p *= (num[i] - '0');
            s += (num[i] - '0');
        }

        return (n % (p + s)) == 0;
    }
};