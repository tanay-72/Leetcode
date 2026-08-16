class Solution {
public:
    int maximumGap(string skill, string station) {
        unordered_map<int , int> ear ;
        int ptr = 0 ;
        for(int i = 0 ; i < skill.size() ;i++){
            while(station[ptr] != skill[i]) ptr++;
            ear[i] = ptr;
            ptr++;
        } 
        unordered_map<int,int> lat;
        ptr = station.size()-1;
        int ans = 0 ;
        for(int i = skill.size() - 1 ; i >= 0 ; i--){
            while(station[ptr] != skill[i]) ptr--;
            lat[i] = ptr;
            ptr--;
            if(i >= 1)ans = max(ans , lat[i] - ear[i-1]);
        }
        return ans;
    }
};
// first take min poss idx for each skill[i]
// then from right try txtending to max poss idx 