class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low, mid, high;
        low = 0;
        high = nums.size() - 1;

        // Keep searching until low <= high
        while(low<=high){

            mid = (low + high)/2;

            if(nums[mid] > target){
                high = mid -1;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
            else if(nums[mid] == target){
                return mid;
            }
        }
        return -1;

    }
};
