class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans = 0;
        int mx = INT_MIN;

        for(int ele:lights) mx = max(mx, ele);

        for(int ele:arrivalTime) {
            int r = ele % period;
            if(r >= mx) ans = max(ans, period - r);
        }
        
        return ans;
    }
};