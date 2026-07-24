class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> f;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i ++) {
            for(int j = i ; j < n ; j++) f.insert(nums[i]^nums[j]);
        }
        unordered_set<int> s;
        for(int i = 0 ; i < nums.size() ; i++){
            for(auto x : f){
                s.insert(nums[i]^x);
            }
        }
        return s.size();
    }
};

// find set of xor of 2 elements then take xor with 3rd element