class Solution {
public:
    int sumCounts(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for(int i = 0;i < n;i++) {
            mp[v[i]]++;
            unordered_map<int, int> temp = mp;
            for(int j = 0;j <= i;j++) {
                ans += temp.size() * temp.size();
                temp[v[j]]--;
                if(temp[v[j]] == 0) temp.erase(v[j]);
            }
        }
        return ans;
    }
};