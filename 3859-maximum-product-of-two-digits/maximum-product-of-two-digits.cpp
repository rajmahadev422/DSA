class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        priority_queue<int, vector<int> , greater<int>> pq;
        pq.push(n % 10);
        n /= 10;
        pq.push(n % 10);
        n /= 10;
        while(n > 0) {
            cout<<pq.top()<<" ";
            if(pq.size() >= 2 and pq.top() < n % 10) {
                pq.pop();
                pq.push(n % 10);
            }
            n = n / 10;
        }

        if(pq.size() == 1) return pq.top();
        int a = pq.top();
        pq.pop();

        return pq.top() * a;
    }
};