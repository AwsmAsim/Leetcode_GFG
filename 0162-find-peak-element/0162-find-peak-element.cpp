class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        long long start = 0, end = nums.size()-1, mid;
        int n = nums.size();
        
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        while(start <= end){
            mid = (start + end) >> 1;
            // cout << start << " " << mid  << " " << end << endl;
            // cout << nums[mid - 1] << " " << nums[mid] << " " << nums[mid+1] << endl;
            // cout << (mid > 0 and nums[mid] > nums[mid-1]) << " " << (mid < n-1 and nums[mid] > nums[mid+1]) << endl; 
            
            if((mid > 0 and nums[mid] > nums[mid-1]) and (mid < n-1 and nums[mid] > nums[mid+1])){
                return mid;
            }
            else if((mid > 0 and nums[mid-1] > nums[mid])){
                end = mid - 1;
            }else if(mid < n-1 and nums[mid + 1] > nums[mid]){
                start = mid + 1;
            }
            // cout << start << " " << mid  << " " << end << endl;
        }
        
        return mid;
        
    }
};