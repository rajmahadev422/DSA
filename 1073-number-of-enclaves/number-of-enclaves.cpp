class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int &tot) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[i].size() or grid[i][j] == 0) return;

        grid[i][j] = 0;
        tot--;

        dfs(grid, i + 1, j, tot);
        dfs(grid, i - 1, j, tot);
        dfs(grid, i, j + 1, tot);
        dfs(grid, i, j - 1, tot);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int tot = 0;

        for(int i = 0;i < grid.size();i++) {
            for(int ele:grid[i]) if(ele == 1) tot++;
        }

        for(int i = 0;i < 1;i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    tot--;
                    dfs(grid, i + 1, j, tot);
                    dfs(grid, i - 1, j, tot);
                    dfs(grid, i, j + 1, tot);
                    dfs(grid, i, j - 1, tot);
                }
            }
        };

        for(int i = grid.size() - 1;i < grid.size();i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    tot--;
                    dfs(grid, i + 1, j, tot);
                    dfs(grid, i - 1, j, tot);
                    dfs(grid, i, j + 1, tot);
                    dfs(grid, i, j - 1, tot);
                }
            }
        }
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < 1;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    tot--;
                    dfs(grid, i + 1, j, tot);
                    dfs(grid, i - 1, j, tot);
                    dfs(grid, i, j + 1, tot);
                    dfs(grid, i, j - 1, tot);
                }
            }
        };

        for(int i = 0;i < grid.size();i++) {
            for(int j = grid[i].size() - 1;j < grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    tot--;
                    dfs(grid, i + 1, j, tot);
                    dfs(grid, i - 1, j, tot);
                    dfs(grid, i, j + 1, tot);
                    dfs(grid, i, j - 1, tot);
                }
            }
        }


        return tot;
    }
};