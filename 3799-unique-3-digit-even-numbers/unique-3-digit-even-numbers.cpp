class Solution {
public:
    int num(int a, int b, int c) {
        string str = "";
        str += to_string(a);
        str += to_string(b);
        str += to_string(c);

        int ans = stoi(str);
        if(ans >= 100 and ans % 2 == 0) return ans;
        return -1;
    }
    int totalNumbers(vector<int>& d) {
        set<int> st;
        st.insert(-1);
        int n = d.size();
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                for(int k = j + 1;k < n;k++) {
                    st.insert(num(d[i], d[j], d[k]));
                    st.insert(num(d[i], d[k], d[j]));
                    st.insert(num(d[k], d[j], d[i]));
                    st.insert(num(d[k], d[i], d[j]));
                    st.insert(num(d[j], d[k], d[i]));
                    st.insert(num(d[j], d[i], d[k]));
                }
            }
        }
        return st.size() - 1;;
    }
};