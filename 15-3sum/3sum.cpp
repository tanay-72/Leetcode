class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin() , nums.end());
        set<vector<int>> s;
        for(int i = 0 ; i < nums.size() ; i ++){
            int target = -1 * nums[i];
            int l = i+1 , h = nums.size()-1;
            while(l < h){
                if(nums[l] + nums[h] == target){
                    s.insert({nums[i] , nums[l] , nums[h]});
                    l++;
                    h--;
                }
                else if (nums[l] + nums[h] > target) h--;
                else l++;
            }
        }
        for(auto &x : s) v.push_back(x);
        return v ; 
    }
};