class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size()-1, mid;
        
        while(start <= end){
            mid = start + (end - start)/2;
            // cout << start << " " << end << " " << mid << endl;
            if(nums[mid] == target or start == end){
                break;
            }
            // check if the left subarray is sorted
            if(nums[mid] >= nums[start]){
                if(target <= nums[mid] and target >= nums[start]){
                    end = mid - 1;
                }else start = mid + 1;
            }else{
                if(target <= nums[end] and target >= nums[mid]){
                    start = mid + 1;
                }else end = mid -1;
            }
        }
        if(nums[mid]!=target) return -1;
        return mid;
        
    }
};