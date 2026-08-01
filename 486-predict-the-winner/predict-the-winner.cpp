class Solution {
public:
    int dp[21][21];
    int solve(vector<int> &nums , int i , int j){
        if(i > j) return 0 ;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int takei = nums[i] + min(solve(nums , i+1 , j-1) , solve(nums , i+2 , j));
        int takej = nums[j] + min(solve(nums , i , j-2) , solve(nums , i+1 , j-1));
        return dp[i][j] = max(takei , takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int p1 =  solve(nums , 0 , nums.size()-1);
        return p1 >= sum - p1;
    }
};