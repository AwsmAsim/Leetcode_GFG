class Solution {
    
    int recursive(vector<int>& nums, int idx)
    {
        if(idx >= nums.size()) return 0;
        int pick = nums[idx] + recursive(nums, idx + 2);
        int nonPick = recursive(nums, idx + 1);
        
        return max(pick, nonPick);
    }
    
    int tab1(vector<int>& nums){
        // cout << 1 << endl;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);

        // cout << 2 << endl;
        vector<int> dp(nums.size()+1, 0);
        // cout << 3 << endl;
        dp[1]=nums[0], dp[2] = max(nums[0], nums[1]);
        

        for(int i = 2; i <= nums.size(); i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }

        // for(int a: dp) cout << a << ", ";
        // cout << endl;
        // return 0;
        return dp[dp.size()-1];
    }
    
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
        // return recursive(nums, 0);
        return tab1(nums);
        return tabulation(nums);
    }
};