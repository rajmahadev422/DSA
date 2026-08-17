class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [effort, i, j] = pq.top();
            pq.pop();

            if (effort > dist[i][j])
                continue;

            if (i == n - 1 && j == m - 1)
                return effort;

            for (int k = 0; k < 4; k++) {

                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                int wt = abs(heights[i][j] - heights[ni][nj]);

                int newEffort = max(effort, wt);

                if (newEffort < dist[ni][nj]) {

                    dist[ni][nj] = newEffort;

                    pq.push({newEffort, ni, nj});
                }
            }
        }

        return 0;
    }
};