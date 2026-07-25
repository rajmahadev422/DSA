class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int> , greater<int>> pq;
        pq.push(n % 10);
        n /= 10;
        pq.push(n % 10);
        n /= 10;
        while(n > 0) {
            if(pq.size() >= 2 and pq.top() < n % 10) {
                pq.pop();
                pq.push(n % 10);
            }
            n = n / 10;
        }

        int ans = pq.top();
        pq.pop();
        return ans * pq.top();
    }
};