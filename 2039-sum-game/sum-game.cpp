class Solution {
public:
    bool solve(int ps, int ss, int pcnt, int scnt) {
        int n = (scnt - pcnt);
        int ax = (n / 2) * 9, an = n * 0;
        int bx = (ps - ss) - (n - n / 2) * 9;
        int bn = (ps - ss) - (n - n / 2) * 0;
        if ((bx <= ax and bx >= an) and (bn >= an and bn <= ax))
            return false;
        
        return true;
    }
    bool sumGame(string num) {
        int ps = 0, ss = 0, pcnt = 0, scnt = 0;

        for (int i = 0; i < num.length() / 2; i++) {
            if (num[i] == '?')
                pcnt++;
            else
                ps += (num[i] - '0');
        }
        for (int i = num.length() / 2; i < num.length(); i++) {
            if (num[i] == '?')
                scnt++;
            else
                ss += (num[i] - '0');
        }
        cout<<ss<<" "<<ps<<endl;
        if (ps > ss) return solve(ps, ss, pcnt, scnt);
        return solve(ss, ps, scnt, pcnt);
    }
};