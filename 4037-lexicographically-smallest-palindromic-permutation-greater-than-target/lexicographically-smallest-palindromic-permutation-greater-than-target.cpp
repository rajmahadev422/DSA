class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) {
            return "";
        }

        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        vector<int> rem = halfCnt;
        bool possible = true;

        for (int i = 0; i < half; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        if (possible) {
            string left = target.substr(0, half);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2) {
                candidate += mid;
            }

            candidate += right;

            if (candidate > target) {
                return candidate;
            }
        }

        for (int i = half - 1; i >= 0; i--) {

            vector<int> available = halfCnt;

            bool validPrefix = true;

            for (int k = 0; k < i; k++) {
                int x = target[k] - 'a';

                if (available[x] == 0) {
                    validPrefix = false;
                    break;
                }

                available[x]--;
            }

            if (!validPrefix) {
                continue;
            }

            int current = target[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (available[c] == 0) {
                    continue;
                }

                available[c]--;

                string left = target.substr(0, i);
                left += char('a' + c);

                for (int x = 0; x < 26; x++) {
                    left += string(available[x], char('a' + x));
                }

                string right = left;
                reverse(right.begin(), right.end());

                string candidate = left;

                if (n % 2) {
                    candidate += mid;
                }

                candidate += right;

                if (candidate > target) {
                    return candidate;
                }

                available[c]++;
            }
        }

        return "";
    }
};