class Solution {
public:
    unordered_map<char,int> freq;
    unordered_map<char,int> windfreq ;
    bool check(){
        for(auto it = freq.begin() ; it != freq.end() ; it++){
            if(!windfreq.count(it->first)) return false;
            if(windfreq[it->first] < it->second) return false;
        }
        return true ;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        for(int i = 0 ; i < t.size() ; i++) freq[t[i]]++;
        int l = 0 ;
        int r = 0 ;
        while(r<n){
            if(check()) break ;
            windfreq[s[r]]++;
            r++;
        }
        if(!check()) return "";
        r--;
        int beststart = l , bestend = r;
        while(l <= r && r < n){
            windfreq[s[l]]--;
            l++;
            while(r < n){
                if(check()) break;
                r++;
                windfreq[s[r]]++;
            }
            if(!check()) break;
            if(bestend - beststart > r-l) {
                bestend = r , beststart = l ;
            }
        }
        string ans ;
        for(int i = beststart ; i <= bestend ; i++) ans.push_back(s[i]);
        return ans ;
    }
};