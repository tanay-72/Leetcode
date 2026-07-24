class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i ++) {
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mn = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            vector<int> dist(n , 0);
            queue<pair<int,int>> q ; 
            q.push({i,-1});
            vector<bool> visited(n,false);
            visited[i] = true;
            while(!q.empty()){
                auto p = q.front();
                int u = p.first , par = p.second ;
                q.pop();
                for(auto &v : adj[u]){
                    if(visited[v] && v != par){
                        mn = min(mn , dist[v] + dist[u] + 1);
                    }
                    if(!visited[v]){
                        dist[v] = 1 + dist[u];
                        visited[v] = true ;
                        q.push({v,u});
                    }
                }
            }
        }
        return mn == INT_MAX ? -1 : mn ; 
    }
};