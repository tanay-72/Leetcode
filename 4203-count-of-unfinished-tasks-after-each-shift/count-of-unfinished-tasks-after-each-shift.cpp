class Solution {
public:
    using ll = long long;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<ll> pref(n);
        pref[0] = tasks[0]; for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + tasks[i];
        vector<int> ans ; 
        int start = 0 ;
        ll carry = 0 ;
        for(int i = 0 ; i < shifts.size() ; i++){
            int l = start ; int h = n-1;
            int ele = -1;
            int s = shifts[i] + carry;
            while(l <= h){ // find the last element less than eq to shifts[i]
                int mid = l + (h-l)/2 ;
                ll sum = pref[mid];
                if(start != 0) sum -= pref[start-1];
                if(sum <= s){
                    ele = mid;
                    l = mid + 1;
                }
                else h = mid-1;
            }
            if(ele == -1){
                ans.push_back(n-start);
                carry = s;
                continue;
            }
            else{
                ans.push_back(n - ele - 1);
                carry = (s - (pref[ele] - (start == 0 ? 0 : pref[start-1])));
                start = ele + 1 ;
            }
            if(start == n){
                start = 0;
                carry = 0;
            }
        }
        return ans ;
    }
};