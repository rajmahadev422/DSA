class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(true) {
            string str = to_string(n);

            int p = 1;

            for(int i = 0;i < str.length();i++) p *= (str[i] - '0');
            cout<<p<<" ";
            if(p % t == 0) {
                return n;
            }
            
            n++;
        }
    }
};