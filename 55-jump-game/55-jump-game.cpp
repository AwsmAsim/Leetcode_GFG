class Solution {
    
    void _print(vector<int> arr){
        for(int num: arr) cout << num << ", ";
        cout << endl;
    }
    
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 0);
        dp[nums.size()-1] = 1;
        int i = nums.size()-1;
        
        for(; i >= 0; i--){
            for(int j = i + 1 ; j <= min((int)i + nums[i], (int) nums.size()-1); j++){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        // _print(dp);
        
        return dp[0];
    }
};