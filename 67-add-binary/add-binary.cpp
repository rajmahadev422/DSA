class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int rem = 0;

        int n = a.length(), m = b.length();

        if(n > m) return addBinary(b, a);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i = 0;i < n;i++) {
            int s = (a[i] - '0') + (b[i] - '0') + rem;
            ans += to_string((s % 2));
            rem = s/2;
        };

        for(int i = n;i < m;i++) {
            int s = (b[i] - '0') + rem;
            ans += to_string(s % 2);
            rem = s / 2;
        }
        if(rem) ans += to_string(rem);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};