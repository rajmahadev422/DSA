class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, bool>& p) const {
            return hash<int>()(p.first) ^ (hash<bool>()(p.second) << 1);
        }
    };

    bool solve(int n, vector<int>& v, bool turn,
               unordered_map<pair<int, bool>, bool, PairHash>& m) {

        if (n == 0)
            return !turn;

        if (m.contains({n, turn}))
            return m[{n, turn}];

        if (turn) {
            bool ans = false;

            for (int ele : v) {
                if (ele <= n) {
                    ans = ans || solve(n - ele, v, !turn, m);
                }
            }

            return m[{n, turn}] = ans;
        }

        bool ans = true;

        for (int ele : v) {
            if (ele <= n) {
                ans = ans && solve(n - ele, v, !turn, m);
            }
        }

        return m[{n, turn}] = ans;
    }

    bool winnerSquareGame(int n) {

        vector<int> v;

        for (int i = 1; i * i <= n; i++) {
            v.push_back(i * i);
        }

        unordered_map<pair<int, bool>, bool, PairHash> m;

        return solve(n, v, true, m);
    }
};