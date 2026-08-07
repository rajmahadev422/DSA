
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int counts[4] = {0, 0, 0, 0};
        int primes[4] = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (temp % primes[i] == 0) {
                temp /= primes[i];
                counts[i]++;
            }
        }
        if (temp > 1) return "-1";
        
        vector<long long> divs;
        auto get_divs = [&](auto& self, int idx, long long cur) -> void {
            if (idx == 4) {
                divs.push_back(cur);
                return;
            }
            long long p = primes[idx];
            for (int i = 0; i <= counts[idx]; ++i) {
                self(self, idx + 1, cur);
                cur *= p;
            }
        };
        get_divs(get_divs, 0, 1);
        sort(divs.begin(), divs.end());
        
        map<long long, int> dp;
        dp[1] = 0;
        for (long long u : divs) {
            if (u == 1) continue;
            dp[u] = 1e9;
            for (int d = 2; d <= 9; ++d) {
                long long g = std::gcd(u, (long long)d);
                if (g > 1) {
                    dp[u] = min(dp[u], 1 + dp[u / g]);
                }
            }
        }
        
        bool has_zero = false;
        int first_zero = -1;
        vector<long long> pref(num.length() + 1, 1);
        pref[0] = t;
        
        for (int i = 0; i < num.length(); ++i) {
            if (num[i] == '0' && !has_zero) {
                has_zero = true;
                first_zero = i;
            }
            if (!has_zero) {
                pref[i + 1] = pref[i] / std::gcd(pref[i], (long long)(num[i] - '0'));
            }
        }
        
        if (!has_zero && pref[num.length()] == 1) return num;
        
        auto build_smallest = [&](long long r, int len) {
            string res(len, '1');
            for (int i = 0; i < len; ++i) {
                for (int d = 1; d <= 9; ++d) {
                    long long nxt = r / std::gcd(r, (long long)d);
                    if (dp.count(nxt) && dp[nxt] <= len - 1 - i) {
                        res[i] = d + '0';
                        r = nxt;
                        break;
                    }
                }
            }
            return res;
        };
        
        int limit = has_zero ? first_zero : (int)num.length() - 1;
        for (int i = limit; i >= 0; --i) {
            long long cur_req = pref[i];
            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                long long nxt = cur_req / std::gcd(cur_req, (long long)d);
                if (dp.count(nxt) && dp[nxt] <= (int)num.length() - 1 - i) {
                    return num.substr(0, i) + to_string(d) + build_smallest(nxt, num.length() - 1 - i);
                }
            }
        }
        
        int len = max((int)num.length() + 1, dp[t]);
        return build_smallest(t, len);
    }
};