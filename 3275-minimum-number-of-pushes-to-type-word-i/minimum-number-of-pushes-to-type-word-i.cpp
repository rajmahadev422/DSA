class Solution {
public:
    int minimumPushes(string word) {
     int n = word.length();
    int a = n / 8;

     int ans = 4*(a*(a+1)) + (n - a*8)*(a+1); 
     return ans;  
    }
};