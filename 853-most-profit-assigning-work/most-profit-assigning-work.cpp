class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n = profit.size() ; 
        for(int i = 0 ; i < n ; i++){
            v.push_back({profit[i] , difficulty[i]});
        }
        sort(v.begin() , v.end() , [](pair<int , int> &a , pair<int,int> &b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second ;
        });
        long long ans = 0;
        sort(worker.begin() , worker.end());
        int taken = worker.size()-1;
        for(int i = 0 ; i < n ; i++){
            if(taken < 0) break;
            int diff = v[i].second ;
            int l = 0 ;
            int h = taken ;
            int ele = -1 ;
            while(l <= h){ // find first worker with strength >= diff
                int mid = l + (h-l)/2;
                if(worker[mid] >= diff){
                    ele = mid ;
                    h = mid-1; 
                }
                else l = mid + 1; 
            }
            if(ele == -1) continue ;
            ans += 1LL * v[i].first * (taken - ele + 1);
            taken = ele - 1 ;
        }
        return ans ;
    }
};
// for each best job how many workers can do it 