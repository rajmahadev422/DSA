class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        priority_queue< pair< int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;

        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            string str = "";
            for (int j = i; j < s.length(); j++) {

                if (s[j] == '1')
                    cnt++;
                if (cnt > 0)
                    str += s[j];
                if (cnt == k) {
                    pq.push(make_pair(str.length(), str));
                    break;
                }
            }
        }

        if (pq.size() == 0)
            return "";
        

        return pq.top().second;
    }
};