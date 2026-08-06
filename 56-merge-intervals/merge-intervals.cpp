class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(int i = 1;i < intervals.size();i++) {
            vector<int> v = intervals[i];

            if(ans.back()[1] >= v[0]) ans.back()[1] = max(ans.back()[1], v[1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};