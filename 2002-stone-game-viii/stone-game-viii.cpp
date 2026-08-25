class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;

        for (int x : stones)
            sum += x;

        int ans = sum;

        for (int i = n - 1; i >= 2; i--) {
            sum -= stones[i];
            ans = max(ans, sum - ans);
        }

        return ans;
    }
};