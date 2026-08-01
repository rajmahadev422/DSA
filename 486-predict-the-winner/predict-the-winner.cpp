class Solution {
public:
    bool predict(int l, int r, int a, int b, vector<int> &v, bool turn) {

        if(l > r) return a >= b;
        if(turn) return predict(l + 1, r, a + v[l], b, v, !turn) or predict(l, r - 1, a + v[r], b, v, !turn);
        return predict(l + 1, r, a, b + v[l], v, !turn) and predict(l, r - 1, a, b + v[r], v, !turn);
    }
    bool predictTheWinner(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return predict(l, r, 0, 0, nums, true);
    }
};