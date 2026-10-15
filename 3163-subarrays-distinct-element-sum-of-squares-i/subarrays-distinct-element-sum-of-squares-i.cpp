class Solution {
public:
    int sumCounts(vector<int>& v) {
        int n = v.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (mp[v[j]] == 0) {
                    distinct++;
                }

                mp[v[j]]++;
                ans += 1LL * distinct * distinct;
            }
        }

        return ans;
    }
};