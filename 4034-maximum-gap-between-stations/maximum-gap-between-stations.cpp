class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> left(n), right(n);
        int idx = 0;
        for(int i = 0;i < m and idx < n;i++) {
            if(station[i] == skill[idx]) left[idx++] = i;
        }
        idx = n - 1;

        for(int i = m - 1;i >= 0 and idx >= 0;i--) {
            if(station[i] == skill[idx]) right[idx--] = i;
        }

        int ans = 0;

        for(int i = 1;i < n;i++) ans = max(ans, right[i] - left[i - 1]);

        return ans;
    }
};