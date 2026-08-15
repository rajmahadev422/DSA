class Solution {
public:
    unordered_map<int, int> dp;
    void solve(int idx, int x, int n, vector<int> & nums, priority_queue<int, vector<int>, greater<int> > &pq) {
        if(dp.contains(idx) and dp[idx] >= n) return;
        if(x != 0) {
            pq.push(n);
            if(pq.size() == 2) pq.pop();
            dp[idx] = n;
        }
        if(idx >= nums.size()) return;

        solve(idx + 1, x ^ nums[idx], n + 1, nums, pq);
        solve(idx + 1, x, n, nums, pq);
    }
    int longestSubsequence(vector<int>& nums) {
        int cnt = 0, x = 0;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == 0) cnt++;
            x = x ^ nums[i];
        }
        if(x != 0) return nums.size();
        if(cnt == nums.size()) return 0;
        
        priority_queue<int, vector<int>, greater<int> > pq;
        solve(0, 0, 0, nums, pq);
        if(pq.size() == 2) pq.pop();
        return pq.top();
    }
};