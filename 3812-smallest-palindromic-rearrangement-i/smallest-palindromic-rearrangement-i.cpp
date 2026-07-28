class Solution {
public:
    string smallestPalindrome(string s) {
        map <char , int> mp ;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        int n = s.size();
        vector<char> v(n);
        int j = 0 ;
        char c ;
        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            int count = it->second ;
            for(int i = 0 ; i < (it->second) / 2 ; i++){
                v[j+i] = it->first ;
                v[n-(j+i)-1] = it->first ;
            }
            if(it->second % 2) c = it->first;
            j += it->second / 2 ;
        }
        if(n % 2) v[n/2] = c ;
        string ans ; 
        for(int i = 0 ; i < n ; i++) ans.push_back(v[i]);
        return ans ;
    }
};
// j = 0   i = 0 to 0  v[0] , v[n-1]  , j = 1 
// j = 1  i = 1 to 1 v[1] , v[n-2] , j = 2 
// j = 2 
