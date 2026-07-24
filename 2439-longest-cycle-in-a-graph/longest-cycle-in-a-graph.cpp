class Solution {
public:
    int mx = -1;
    void dfs(vector<vector<int>> &adj , vector<bool> &visited , vector<bool> &inrec , int u ,  vector<int>& depth){
        visited[u] =true;
        inrec[u] = true;
        for(auto &v : adj[u]){
            if(visited[v] && inrec[v]){
                mx = max(mx , depth[u] - depth[v] +1);
            }
            if(!visited[v]){
                depth[v] = 1 + depth[u];
                dfs(adj , visited , inrec , v , depth);
            }
        }
        inrec[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i ++){
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        vector<bool> visited(n,false);
        vector<bool> inrec(n,false);
        vector<int> depth(n,0);
        for(int i = 0 ; i< n ; i ++){
            if(!visited[i]){
                dfs(adj , visited , inrec , i , depth);
            }
        }
        return mx ;
    }
};