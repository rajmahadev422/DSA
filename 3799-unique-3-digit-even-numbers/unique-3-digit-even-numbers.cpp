class Solution {
public:
    int totalNumbers(vector<int>& d) {
        vector<int> cnt(10, 0);

        for (int x : d)
            cnt[x]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {
                    if (cnt[a] == 0 || cnt[b] == 0 || cnt[c] == 0)
                        continue;

                    if (a == b && b == c) {
                        if (cnt[a] < 3)
                            continue;
                    } else if (a == b) {
                        if (cnt[a] < 2)
                            continue;
                    } else if (a == c) {
                        if (cnt[a] < 2)
                            continue;
                    } else if (b == c) {
                        if (cnt[b] < 2)
                            continue;
                    }

                    ans++;
                }
            }
        }

        return ans;
    }
};