class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));

        int sx = 0, sy = 0;
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(
                          energy + 1, vector<bool>(1 << litterCount, false))));

        queue<array<int, 5>> q;

        q.push({sx, sy, energy, 0, 0});
        visited[sx][sy][energy][0] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [x, y, e, mask, dist] = q.front();
            q.pop();

            if (mask == fullMask)
                return dist;

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (classroom[nx][ny] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;

                int nmask = mask;

                if (classroom[nx][ny] == 'L') {
                    int idOfLitter = id[nx][ny];
                    nmask |= (1 << idOfLitter);
                }

                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                if (!visited[nx][ny][ne][nmask]) {

                    visited[nx][ny][ne][nmask] = true;

                    q.push({nx, ny, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};