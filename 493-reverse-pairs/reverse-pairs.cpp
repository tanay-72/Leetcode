class Solution {
public:
    int merge(vector<int> &nums , int low , int mid , int high){
        int cnt = 0;

        int right = mid + 1;
        for (int left = low; left <= mid; left++) {
            while (right <= high && (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }
        vector<int> temp ;
        int left = low;
        right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low ; i <= high ; i ++){
            nums[i] = temp[i-low];
        }
        return cnt ;
    }
    int mergeSort(vector<int> &nums , int low , int high){
        if (low >= high)
            return 0;
        int mid = low + (high-low) / 2 ;

        int a = mergeSort(nums , low , mid);
        int b = mergeSort(nums, mid+1 , high);

        int c = merge(nums , low , mid , high);

        return a + b + c;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size() -1);
    }
};