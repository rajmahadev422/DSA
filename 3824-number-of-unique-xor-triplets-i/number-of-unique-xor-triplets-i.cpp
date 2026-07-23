class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;

        int p = 0;

        while ((1 << (p + 1)) <= n)
            p++;

        return 1 << (p + 1);
    }
};