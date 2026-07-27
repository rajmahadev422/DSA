class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > pq;

        for(int i = 0;i < nums.size();i++) {
            if(pq.size() < 2) {
                pq.push(nums[i] - 1);
                continue;
            }
            if(pq.size() >= 2 and pq.top() < nums[i] - 1) {
                pq.pop();
                pq.push(nums[i] - 1);
            }
        }
        int ans = 1;

        while(!pq.empty()) {
            ans *= pq.top();
            pq.pop();
        }
        return ans;
    }
};