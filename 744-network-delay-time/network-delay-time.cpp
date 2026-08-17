class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector< pair<int, int> > >adj;

        for(int i = 0;i < times.size();i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back(make_pair(v, w));
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push(make_pair(dist[k], k));

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [next, wt]: adj[node]) {
                if(d + wt < dist[next]) {
                    dist[next] = d + wt;
                    pq.push(make_pair(dist[next], next)); 
                }
            }
        }

        int ans = 0;

        for(int ele:dist) {
            if(ele == INT_MAX) return -1;
            ans = max(ans, ele);
        }
        return ans;
    }
};