class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& v) {
        if(v.empty()){
            return n - 1 ;
        }
        v.push_back({1,0});
        sort(v.begin() , v.end());
        for(int i = 1 ; i < v.size();i++){
            v[i][1] = min(v[i][1] , v[i-1][1] + (v[i][0] - v[i-1][0]));
        }
        for(int i = v.size() -2 ; i >= 0 ; i--){
            v[i][1] = min(v[i][1] , v[i+1][1] + (v[i+1][0] - v[i][0]));
        }
        int mx = 0;
        for(int i = 0 ; i < v.size()-1 ; i++){
            mx = max(mx , (v[i+1][0]-v[i][0] + v[i][1] + v[i+1][1]) / 2 );
        }
        mx = max(mx , (v[0][0] - 1 + v[0][1]) / 2);
        mx = max(mx , (n-v[v.size()-1][0] + v[v.size()-1][1]));
        return mx ;
    }
};