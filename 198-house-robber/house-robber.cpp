class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1 ) return nums[0];
        int n = nums.size();
        if(n == 2) return max(nums[0] , nums[1]);
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for(int i = 3 ; i < n ; i++){
            dp[i] = max(dp[i-2] , dp[i-3]) + nums[i];
        }
        return *max_element(dp.begin() , dp.end());
    }
};
// at index i i can come from i-2 or i-3