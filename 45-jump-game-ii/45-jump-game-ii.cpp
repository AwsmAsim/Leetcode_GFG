class Solution {

    
public:
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), INT_MAX);
        
        
        dp[nums.size()-1] = 0;
        for(int i = nums.size()-2; i >= 0; i--){
            int minMoves = INT_MAX;
            for(int j = 1 + i; j <= min(i+nums[i], (int)nums.size()-1); j++){
                minMoves = min(minMoves, dp[j]);
            }
            if(minMoves == INT_MAX) continue;
            dp[i] = 1 + minMoves;
        }
        
        return dp[0];
        
    }
};