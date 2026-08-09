class Solution {
public:
    int bfs(vector<vector<int>> &adj){ 
        queue<pair<int,int>> q ;
        q.push({0,-1});
        int depth = 0 ;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                auto p = q.front();
                int u = p.first ; int par = p.second;
                q.pop();
                for(auto &v : adj[u]){
                    if(v == par) continue;
                    q.push({v , u});
                }
            }
            depth++;
        }
        return depth;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size() ;
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i++){
            int u = i ;
            int v = parent[i];
            if(v == -1) continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int h = bfs(adj);
        queue<pair<int,int>> q ;
        q.push({0,-1});
        long long ans = 0 ;
        int d = 1 ;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i ++){
                auto p = q.front();
                q.pop();
                int u = p.first , par = p.second ;
                ans += (nums[u] * (h-d+1LL));
                for(auto &v : adj[u]){
                    if(v == par) continue;
                    q.push({v,u});
                }
            }
            d++;
        }
        return ans ;
    }
};