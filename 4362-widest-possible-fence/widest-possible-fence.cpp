class Solution {
public:
    using ll = long long;
    int maximumWidth(vector<int>& v) {
        map<ll,ll> mp;
        int n = v.size();
        for(int i =  0 ; i < n ; i++) mp[v[i]]++;
        vector<pair<ll,ll>> vec(mp.begin() , mp.end());
        for(int i = 0 ; i < vec.size() ; i++){
            auto [x,fx] = vec[i];
            for(int j = i + 1 ; j < vec.size() ; j++){
                auto [y,fy] = vec[j];
                mp[x+y] += min(fy,fx);
            }
            mp[x + x] += fx / 2;
        }
        int ans = 1 ;
        for(auto it = mp.begin() ; it!=mp.end() ; it++) ans = max(ans , (int)it->second);
        return ans ;
    }
};