class Solution {
public:
    int maxValidSplits(vector<int>& nums) {

        int res = 0;
        vector<int> temp = nums;

        int n = temp.size();
        vector<int> pf(n);
        vector<int> sf(n);

        pf[0] = temp[0];
        sf[n - 1] = temp[n - 1];

        for (int i = 1; i < n; i++) {
            pf[i] = gcd(pf[i - 1], temp[i]);
        }

        for (int i = n - 2; i >= 0; i--)
            sf[i] = gcd(sf[i + 1], temp[i]);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (sf[i] == pf[i - 1])
                ans++;
        }
        res = max(res, ans);
        for (int k = 0; k < nums.size(); k++) {
            temp = nums;

            temp.erase(temp.begin() + k);

            int n = temp.size();
            vector<int> pf(n);
            vector<int> sf(n);

            pf[0] = temp[0];
            sf[n - 1] = temp[n - 1];

            for (int i = 1; i < n; i++) {
                pf[i] = gcd(pf[i - 1], temp[i]);
            }

            for (int i = n - 2; i >= 0; i--)
                sf[i] = gcd(sf[i + 1], temp[i]);
            int ans = 0;
            for (int i = 1; i < n; i++) {
                if (sf[i] == pf[i - 1])
                    ans++;
            }
            res = max(res, ans);
        }
        return res;
    }
};