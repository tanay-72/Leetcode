class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y)
            return;
        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        } else {
            rank[parent_x]++;
            parent[parent_y] = parent_x;
        }
        return;
    }
    bool isBipartite(vector<vector<int>> &adj , int u , vector<int> &color , int col){
        color[u] = col;
        for(auto &v : adj[u]){
            if(color[v] == color[u]){
                return false;
            }
            if(color[v] == -1){
                if(!isBipartite(adj , v , color , 1-col)) return false;
            }
        }
        return true ;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        parent.resize(n,0); for(int i = 0; i < n ; i ++) parent[i] = i;
        rank.resize(n,0);
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1];
            u-- ; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n,-1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1) {
                if(!isBipartite(adj , i , color , 0)) return -1 ;
            }
        }
        map<int ,vector<int>> component;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1]; 
            u-- ; v--;
            Union(u,v);
        }       
        for(int i = 0 ; i < n ; i++){
            int px = find(i);
            component[px].push_back(i);
        } 
        int ans = 0 ;
        for(auto it = component.begin() ; it != component.end() ; it++){
            vector<int> comp = it->second ;
            int mx = 0 ;
            for(int j = 0 ; j < comp.size() ; j++){
                queue<int> q ;
                q.push(comp[j]);
                vector<bool> visited(n,false);
                visited[comp[j]] = true;
                int d = 0;
                while(!q.empty()){
                    int sz = q.size();
                    for(int i = 0 ; i < sz ; i++){
                        int u = q.front();
                        q.pop();
                        for(auto &v : adj[u]){
                            if(!visited[v]){
                                visited[v] = true ;
                                q.push(v);
                            }
                        }
                    }
                    d++;
                }
                mx = max(mx , d);
            }
            ans += mx ;
        }
        return ans ;
    }
};
// graph must be bipartite