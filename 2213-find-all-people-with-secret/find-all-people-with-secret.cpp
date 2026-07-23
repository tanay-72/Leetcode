class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knowsecret(n , false);
        knowsecret[0] = true ;
        knowsecret[firstPerson] = true ;
        sort(meetings.begin() , meetings.end() ,[&](vector<int> &a , vector<int>&b){
            return a[2] < b[2];
        });
        unordered_set<int> nodes ;
        for(int i = 0 ; i < meetings.size() ; i++){
            unordered_map<int, vector<int>> adj;
            int time = meetings[i][2];
            int ptr = i ;
            while(ptr < meetings.size() && meetings[ptr][2] == time){
                adj[meetings[ptr][0]].push_back(meetings[ptr][1]);
                adj[meetings[ptr][1]].push_back(meetings[ptr][0]);
                nodes.insert(meetings[ptr][0]);
                nodes.insert(meetings[ptr][1]);
                ptr++;
            }
            ptr-- ; i = ptr;
            queue<int> q ;
            unordered_set<int> visited;
            for(auto &x : nodes){
                if(knowsecret[x]){
                    q.push(x);
                } 
            }
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if (visited.count(u)) continue;
                visited.insert(u);
                for(auto &v : adj[u]){
                    if(!visited.count(v)){
                        if(knowsecret[u]) {
                            knowsecret[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            nodes.clear();
        }
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++) if(knowsecret[i]) ans.push_back(i);
        return ans ;
    }
};