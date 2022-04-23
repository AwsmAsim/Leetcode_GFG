class Solution {
    
public:
    int firstMissingPositive(vector<int>& nums) {
        int currElement = nums[0], n = nums.size(), temp;
        
        for(int i = 0; i < n; i++){
            while(nums[i]!= i+1 and (nums[i]<=n and nums[i]>0)){
                if(nums[i] == nums[nums[i]-1]) break;
                temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        
        // for(auto a: nums) cout << a << " "; 
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        
        
        return n+1;
    }
};