class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int t = 0;
        for (int i = 0; i < n; i++) {
            if(matrix[i][0] > target or matrix[i][m-1] < target) continue;
            int l = 0, r = m - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (matrix[i][mid] == target)
                    return true;

                if (matrix[i][mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};