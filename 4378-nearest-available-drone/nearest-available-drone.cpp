class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX;
        int rob = -1;
        for(int i = 0 ; i < drones.size() ; i ++){
            int dist = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(dist > drones[i][2]) continue;
            if(dist < ans){
                 ans = min(ans , dist);
                 rob = i ;
            }
        }
        return rob ;
    }
};