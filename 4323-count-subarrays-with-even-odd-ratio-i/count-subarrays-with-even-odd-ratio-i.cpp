class Solution {
public:
    bool isval(int x , int y , int a , int b){
        return x * b <= a * y ;
    }
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
        for(int len = 1 ; len <= n ; len++){
            int x = 0 , y = 0;
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1 ;
                if(nums[j] % 2) y ++ ;
                else x++;
                if(isval(x , y , a , b)) ans++;
            }
        }
        return ans;
    }
};