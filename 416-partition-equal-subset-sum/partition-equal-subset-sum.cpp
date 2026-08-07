class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[n][target] = true;
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int currsum = target; currsum >= 0; currsum--) {
                bool skip = dp[idx + 1][currsum];
                bool take = false;
                if(currsum + nums[idx] <= target) take = dp[idx + 1][currsum + nums[idx]];
                dp[idx][currsum] = take || skip;
            }
        }
        return dp[0][0];
    }
};