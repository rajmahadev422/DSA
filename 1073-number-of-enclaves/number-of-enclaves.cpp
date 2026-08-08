class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& tot) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[i].size() or
            grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        tot--;

        dfs(grid, i + 1, j, tot);
        dfs(grid, i - 1, j, tot);
        dfs(grid, i, j + 1, tot);
        dfs(grid, i, j - 1, tot);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int tot = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int ele : grid[i])
                if (ele == 1)
                    tot++;
        }

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i != 0 && i != n - 1 && j != 0 && j != m - 1)
                    continue;

                if (grid[i][j] == 1) {
                    
                    dfs(grid, i, j, tot);
                }
            }
        }

        return tot;
    }
};