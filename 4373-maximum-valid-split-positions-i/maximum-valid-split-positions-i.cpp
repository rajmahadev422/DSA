class Solution {
public:
    int solve(int idx, vector<int>& v) {
        vector<int> temp = v;

        if (idx != -1)
            temp.erase(temp.begin() + idx);

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
        return ans;
    }
    int maxValidSplits(vector<int>& nums) {

        int res = 0;
        
        for (int k = -1; k < (int)nums.size(); k++) res = max(res, solve(k, nums));
        return res;
    }
};