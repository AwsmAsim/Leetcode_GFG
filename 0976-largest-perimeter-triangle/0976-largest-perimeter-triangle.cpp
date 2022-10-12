class Solution {

    
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.rbegin(), nums.rend());
        
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i+1] + nums[i+2] > nums[i]){
                return (nums[i+2] + nums[i+1] + nums[i]);
            }
        }
        
        
        return 0;
        
    }
};