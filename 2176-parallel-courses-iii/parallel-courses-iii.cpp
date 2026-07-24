class Solution {
public:
    vector<int> dp;
    int dfs(vector<vector<int>> &rev , int u , vector<int>&time){
        if(dp[u] != -1) return dp[u];
        int cal = 0 ;
        for(auto &v : rev[u]){
            cal = max(cal , dfs(rev , v , time));
        }
        cal += time[u];
        return dp[u] = cal ;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> rev(n) ;
        for(int i = 0 ; i < relations.size() ; i ++){
            int u = relations[i][0] , v = relations[i][1];
            u--; v--;
            rev[v].push_back(u);
        }
        dp.resize(n,-1);
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == -1) dfs(rev , i , time);
        }
        return *max_element(dp.begin() , dp.end());
    }
};