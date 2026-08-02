class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0 ;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                long long l = __gcd(nums[i] , nums[j]) ;
                ans = max(ans , (nums[i] * (long long)nums[j]) / (1LL *l * l ));
            }
        }
        return ans;
    }
};