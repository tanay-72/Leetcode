class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        vector<int> ans ;
        int n = spells.size();
        for(int i = 0 ; i < n ;i++){
            int l = 0 ; 
            int h = potions.size()-1;
            int ele = -1 ;
            while(l<=h){ // find first element greater than eq to target 
                int mid = l + (h-l)/2 ;
                if(spells[i] * (long long)potions[mid] >= success){
                    ele = mid ;
                    h = mid-1;
                }
                else{
                    l = mid + 1 ;
                }
            }
            if(ele != -1) {
                ans.push_back(potions.size()- ele);
            }
            else ans.push_back(0);
        }
        return ans ;
    }
};

// s * p >= success