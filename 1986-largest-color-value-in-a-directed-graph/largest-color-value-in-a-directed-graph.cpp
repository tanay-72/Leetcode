class Solution {
public:
    string l;
    bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    return cnt != n;  
}
    void dfs(vector<vector<int>> &adj , vector<bool> &visited , int u , vector<vector<int>> &dp){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v]){
                dfs(adj , visited , v , dp);
            }
            for(int j = 0 ; j < 26 ; j++){
                dp[u][j] = max(dp[u][j] , dp[v][j]);
            }
        }
        dp[u][l[u]-'a']++;
        return ;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        l = colors;
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
        }
        if(hasCycle(n , adj)) return -1 ;
        vector<bool> visited(n , false);
        vector<vector<int>> dp(n , vector<int> (26,0)); 
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(adj , visited , i , dp);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , *max_element(dp[i].begin() , dp[i].end()));
        }   
        return ans;
    }
};
// for each node I will maintain the frequency of each char that have been occured in subtrees
// dp[u] += dp[v] then dp[u][s[u]-'a']++ ;
// traverse for each component  