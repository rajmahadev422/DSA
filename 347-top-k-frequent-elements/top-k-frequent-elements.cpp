class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;

        for(int i = 0;i < nums.size();i++) {
            m[nums[i]]++;
        }

        for(auto p: m) pq.push({p.second, p.first});
        vector<int> ans;
    
        while(!pq.empty() and ans.size() < k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};