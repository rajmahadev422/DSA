class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if(sum > num * 9) return "";
        string ans = "";
        int s = 0;

        for(int i = 0;i < num;i++) {
            if(sum <= 0) ans += "0";
            else {
                if(sum >= 9) {
                    ans += "9";
                    sum -= 9;
                }
                else {
                    ans += to_string(sum);
                    sum = 0;
                }
            }
        }
        return ans;
    }
};