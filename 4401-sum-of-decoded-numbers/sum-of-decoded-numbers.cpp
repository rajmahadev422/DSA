class Solution {
public:
    long long MOD = 1e9 + 7;
    long long modPow(long long x, long long y) {
        long long ans = 1;

        x %= MOD;

        while (y > 0) {
            if (y & 1)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        unsigned long long ans = 0;

        for (long long i = 0; i < nums.size(); i++) {
            int w = nums[i] % 10;
            string d = to_string(nums[i] / 10);

            int x = 0, y = 0;

            for (int i = 0; i < d.size(); i++) {
                if (i < w)
                    x = x * 10 + int(d[i] - '0');
                else
                    y = y * 10 + int(d[i] - '0');
            }
            ans = (ans + modPow(x, y)) % MOD;
        }

        return ans;
    }
};