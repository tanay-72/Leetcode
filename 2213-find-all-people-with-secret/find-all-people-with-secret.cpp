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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        vector<bool> knowsecret(n , false);
        knowsecret[0] = true ;
        knowsecret[firstPerson] = true ;
        sort(meetings.begin() , meetings.end() ,[&](vector<int> &a , vector<int>&b){
            return a[2] < b[2];
        });
        unordered_set<int> nodes ;
        unordered_set<int> ans ;
        ans.insert(0);
        ans.insert(firstPerson);
        for(int i = 0 ; i < meetings.size() ; i++){
            int time = meetings[i][2];
            int ptr = i ;
            while(ptr < meetings.size() && meetings[ptr][2] == time){
                int u = meetings[ptr][0] , v = meetings[ptr][1] ;
                nodes.insert(u);
                nodes.insert(v);
                Union(u,v);
                ptr++;
            }
            ptr-- ; i = ptr;
            unordered_set<int> comp;
            for(auto &x : nodes){
                if(knowsecret[x]) comp.insert(find(x));
            }
            for(auto &x : nodes){
                if(comp.count(find(x))){
                    knowsecret[x] = true;
                    ans.insert(x);
                }
            }
            for (auto &x : nodes) {
                if (!comp.count(find(x))) {
                    parent[x] = x;
                    rank[x] = 0;
                }
            }
            nodes.clear();
        }
        vector<int> res;
        for(auto &x : ans) res.push_back(x);
        return res ;
    }
};