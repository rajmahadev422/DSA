
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> positions[26];

        for (int i = 0; i < n; i++) {
            positions[word1[i] - 'a'].push_back(i);
        }
        vector<int> exact(m, -1);

        vector<int> almost(m, -1);
        auto getPrev = [&](int c, int limit) -> int {
            auto& v = positions[c];

            auto it = lower_bound(v.begin(), v.end(), limit);

            if (it == v.begin())
                return -1;

            --it;
            return *it;
        };

        auto getPrevDifferent = [&](int c, int limit) -> int {
            int ans = -1;

            for (int x = 0; x < 26; x++) {
                if (x == c)
                    continue;

                int p = getPrev(x, limit);
                ans = max(ans, p);
            }

            return ans;
        };

        int nextLimit = n;

        for (int j = m - 1; j >= 0; j--) {
            int c = word2[j] - 'a';

            exact[j] = getPrev(c, nextLimit);

            if (exact[j] == -1) {

                nextLimit = -1;
            } else {
                nextLimit = exact[j];
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            int c = word2[j] - 'a';

            int exactSuffixFirst = (j + 1 < m) ? exact[j + 1] : n;

            int almostSuffixFirst = (j + 1 < m) ? almost[j + 1] : n;

            int same = getPrev(c, almostSuffixFirst);

            int different = getPrevDifferent(c, exactSuffixFirst);

            almost[j] = max(same, different);
        }

        if (almost[0] == -1)
            return {};

        vector<int> ans;

        int prev = -1;
        bool usedMismatch = false;

        for (int j = 0; j < m; j++) {

            bool found = false;

            for (int i = prev + 1; i < n; i++) {

                bool same = (word1[i] == word2[j]);
                bool mismatch = !same;

                if (mismatch && usedMismatch)
                    continue;

                bool suffixPossible;

                if (j == m - 1) {

                    suffixPossible = true;
                } else if (mismatch) {

                    suffixPossible = (exact[j + 1] > i);
                } else {

                    suffixPossible = (almost[j + 1] > i);
                }

                if (!suffixPossible)
                    continue;

                ans.push_back(i);
                prev = i;

                if (mismatch)
                    usedMismatch = true;

                found = true;
                break;
            }

            if (!found)
                return {};
        }

        return ans;
    }
};