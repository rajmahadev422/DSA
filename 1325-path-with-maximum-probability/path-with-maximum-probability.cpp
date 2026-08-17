class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map< int, vector< pair<int, double> > > adj;

        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue< pair<double, int> > pq;

        vector<double> prob(n, 0);

        prob[start_node] = 1;
        pq.push(make_pair(prob[start_node], start_node));

        while(!pq.empty()) {
            auto [p, node] = pq.top();
            pq.pop();
            for(auto [next, w]: adj[node]) {
                if(prob[next] >= w*p) continue;
                prob[next] = w*p;
                pq.push(make_pair(prob[next], next));
            }
        }
        return prob[end_node];
    }
};