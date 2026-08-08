class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        if(n==1){
            if(s[0] == '0') return "";
            else return "1";
        }
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }
        string cand = "";
        for(int j = 0 ; j < n ; j ++){
            if(s[j] == '0') continue ;
            int target =  pref[j+1] - k;
            if(pref[j+1] == k){
                string p = s.substr(0 , j+1);
                if(cand.empty() || p.size() < cand.size()) cand = p;
                else if  (p.size() == cand.size() && p < cand) cand = p ;
            }
            if(target < 0) continue;
            int l = 0 , h = j ;
            int ele = -1;
            while( l <= h){
                int mid = l + (h-l) /2 ;
                int sum = pref[mid];
                if(sum == target){
                    ele = mid ;
                    l = mid+1;
                }
                else if(sum < target) l = mid+1;
                else h = mid-1;
            }
            if(ele == -1) continue;
            string p = s.substr(ele , j-ele+1);
            if(cand.empty() ||  p.size() < cand.size()) cand = p;
            else if (p.size() == cand.size() && p < cand) cand = p ;
        }
        return cand ;
    }
};

// pref[j] - pref[i-1] == k => pref[i-1] == (k-pref[j]) 
// find max i such that pref[i-1] == pref[j]-k;