class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int prev = 0 ;
        int ans = 0;
        for(int i = 0 ; i < requests.size() ; i ++){
            ans += abs(requests[i] - prev);
            prev = requests[i];
        }
        return ans ;
    }
};