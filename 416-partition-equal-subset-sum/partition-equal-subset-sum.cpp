class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int> &nums , int idx , int currsum , int reqsum){
        if(idx == nums.size()) {
            return 2*currsum == reqsum;
        }
        if(2*currsum == reqsum) return true;

        if(dp[idx][currsum] != -1) return dp[idx][currsum] ;
        // take ;
        bool take = solve(nums , idx + 1 , currsum + nums[idx] , reqsum);

        // skip
        bool skip = solve(nums , idx + 1 , currsum , reqsum);

        return dp[idx][currsum] = take || skip ; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size(); 
        for(int i = 0 ; i < n ; i++) sum += nums[i];
        if(sum % 2 == 1) return false ;
        memset(dp,-1,sizeof(dp));
        return solve(nums , 0 , 0 , sum);
    }
};