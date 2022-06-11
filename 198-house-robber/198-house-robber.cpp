class Solution {
    
    int tabulation(vector<int>& nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        
        return dp[nums.size()-1];
    }
    
public:
    int rob(vector<int>& nums) {
        return tabulation(nums);
    }
};