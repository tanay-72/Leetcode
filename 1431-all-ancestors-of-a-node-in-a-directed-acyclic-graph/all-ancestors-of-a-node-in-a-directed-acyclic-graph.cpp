class Solution {
public:
    vector<vector<int>> ance;
    void dfs(int u , vector<vector<int>> &adj , vector<bool> &visited , vector<int> &p){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v]){
                p.push_back(v);
                dfs(v , adj , visited , p);
            }
        }
        return ;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        ance.resize(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        } 
        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n , false);
            vector<int> p ;
            dfs(i , adj , visited , p);
            sort(p.begin() , p.end());
            ance[i] = p ;
        }
        return ance ;
    }
};