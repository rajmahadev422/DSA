class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        set<pair<float, int>> st;

        int tx = target[0];
        int ty = target[1];
        int idx = 0;
        for(vector<int> drone: drones) {
            int x = drone[0];
            int y = drone[1];
            int r = drone[2];
            double dis = abs(x - tx) + abs(y - ty);
            if(dis <= (double)r) st.insert({dis, idx});
            idx++;
        }
        cout<<st.size()<<endl;
        if(st.size() == 0) return -1;
        return st.begin()->second;
    }
};