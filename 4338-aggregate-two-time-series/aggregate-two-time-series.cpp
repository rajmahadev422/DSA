class Solution {
public:
    int getValue(map<int, int>& mp, int key) {
        auto it = mp.lower_bound(key);

        if (it == mp.end())
            return 0;

        return it->second;
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        map<int, int> ump1;
        map<int, int> ump2;

        set<int> s;
        for (int i = 0; i < series1.size(); i++) {
            ump1[series1[i][0]] = series1[i][1];
            s.insert(series1[i][0]);
        };
        for (int i = 0; i < series2.size(); i++) {
            ump2[series2[i][0]] = series2[i][1];
            s.insert(series2[i][0]);
        };

        vector<vector<int>> ans(s.size(), vector<int>(2));

        int idx = 0;
        for (int ele : s) {
            // cout<<ele<<" ";
            ans[idx][0] = ele;
            ans[idx][1] = getValue(ump1, ele) + getValue(ump2, ele);
            idx++;
        }
        return ans;
    }
};