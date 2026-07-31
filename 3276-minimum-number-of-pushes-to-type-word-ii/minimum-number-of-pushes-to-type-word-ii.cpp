class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(int i = 0;i < word.length();i++) {
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0, cnt = 0, s = 0;
        for(int i = 0;i < 26;i++) {
            if(freq[i] == 0) break;
            cnt++;
            s += freq[i];

            if(cnt % 8 == 0) {
                ans += s * (cnt / 8);
                s = 0;
            }
        }
        ans += s * ((cnt / 8) + 1);
        return ans;
    }
};