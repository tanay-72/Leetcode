class Solution {
public:
    int n ;
    vector<pair<int,int>> dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    bool bfs(vector<vector<int>> &wt , int ub){
        if(wt[0][0] < ub) return false;
        queue<pair<int,int>> q ;
        q.push({0,0}); 
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first , y = p.second ;
            if(x == n-1 && y == n-1) return true ;
            for(auto d : dir){
                int nx = x + d.first , ny = y + d.second;
                if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
                if(wt[nx][ny] < ub) continue;
                if(nx == n-1 && ny == n-1) return true ;
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> wt(n,vector<int> (n,INT_MAX)) ;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) {
            if(grid[i][j] == 1){
            q.push({i,j});
            wt[i][j] = 0 ;}
        }
        while(!q.empty()){
            auto p = q.front();
            int x = p.first , y = p.second;
            q.pop();
            for(auto &d : dir){
                int nx = d.first + x , ny = d.second + y;
                if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
                if(wt[nx][ny] != INT_MAX) continue;
                wt[nx][ny] = 1 + wt[x][y];
                q.push({nx,ny});
            }
        }
        int l = INT_MAX , h = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                l = min(l , wt[i][j]);
                h = max(h , wt[i][j]);
            }
        }
        int ans = 0;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(bfs(wt , mid)){
                ans = mid ;
                l = mid+1;
            }else h = mid-1;
        }
        return ans ;
    }
};