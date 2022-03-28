class Solution {
    
    
    
    
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end=nums.size()-1, mid;
        while(start<=end){
            mid = start + (end - start)/2;
            // cout << mid << endl;
            if(nums[mid] == target or start == end){
                // cout << start << " " << end << endl;
                break;
            }
            if(nums[mid] >= nums[start]){
                // array is sorted on the left
                if(target <= nums[mid] and target >= nums[start]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else if(nums[mid] <= nums[end]){
                // array is sorted on right of mid
                if(target >= nums[mid] and target <= nums[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        
        if(target == nums[mid]) return mid;
        else return -1;
        
    }
};