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
        pair<int, int> p = pq.top();
        ans.push_back(p.second);
        pq.pop();

        while(!pq.empty() and ans.size() < k) {
            if(pq.top().second != ans.back()) ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};