class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        int n = v.size();

        for(int i = 0;i < n;i++) v[i] = abs(v[i]);

        sort(v.begin(), v.end(), greater<int> ());
        long long ans = 0;
        for(int i = 0;i < n;i++) {
            if(i < (n+1)/2) ans += (long long)v[i]*v[i];
            else ans -= (long long)v[i]*v[i];
        }
        return ans;
    }
};