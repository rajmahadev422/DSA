class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i >= grid.size() or j >= grid[0].size()) return INT_MAX;

        if(i == grid.size() - 1 and j == grid[0].size() - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i + 1, j, grid, dp);
        int down = solve(i, j + 1, grid, dp);
        return dp[i][j] = min(left, down) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        return solve(0, 0, grid, dp);
    }
};