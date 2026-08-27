class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string ans = "";

        int i = 0;

        while (i < target.size()) {
            char c = target[i];

            if (mp[c] > 0) {
                ans += c;
                mp[c]--;
                i++;
            } else {
                break;
            }
        }

        if (i < target.size()) {
            auto it = mp.upper_bound(target[i]);

            while (it != mp.end() && it->second == 0)
                it++;

            if (it != mp.end()) {
                ans += it->first;
                mp[it->first]--;

                for (auto& [ch, cnt] : mp) {
                    ans += string(cnt, ch);
                }

                return ans;
            }
        }

        for (int j = ans.size() - 1; j >= 0; j--) {

            mp[ans[j]]++;

            ans.pop_back();

            auto it = mp.upper_bound(target[j]);

            while (it != mp.end() && it->second == 0)
                it++;

            if (it != mp.end()) {

                ans += it->first;
                mp[it->first]--;

                for (auto& [ch, cnt] : mp) {
                    ans += string(cnt, ch);
                }

                return ans;
            }
        }

        return "";
    }
};