class Solution {
public:
    bool solve(vector<int> &nums , int l , int r , int s1 , int s2 , int turn){
        if(l > r){
            return s1 >= s2;
        }

        if(turn == 0){
            bool f1 = solve(nums , l +1 , r , s1 + nums[l] , s2 , 1);
            bool f2 = solve(nums , l , r-1 , s1 + nums[r] , s2, 1);
            return f1 || f2 ;
        }
        
            bool f1 = solve(nums , l + 1 , r , s1 , s2 + nums[l] , 0);
            bool f2 = solve(nums , l , r - 1 , s1 , s2 + nums[r] , 0 );
        return f1 && f2 ;
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums , 0 , nums.size()-1 , 0 , 0 , 0);
    }
};