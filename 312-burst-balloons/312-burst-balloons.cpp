class Solution {
    
    void _print(vector<vector<int>> grid){
        for(auto row: grid){
            for(auto num: row){
                cout << num << ", ";
            }
            cout << endl;
        }
    } 
    

public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        
        int curMax = INT_MIN;
        
        
        
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; j++, i++){
                curMax = INT_MIN;
                for(int k = i; k <= j; k++){
                    
                    // cout << i << " " << j << " " << k << endl;
                    
                    int leftSum, rightSum, val;
                    leftSum = i==k ? 0 : dp[i][k-1];
                    rightSum = k==j ? 0 : dp[k+1][j];
                    val = (i == 0 ? 1 : nums[i-1]) * nums[k] * (j == (n-1) ? 1 : nums[j+1]);
                    // cout << val << endl;
                    int total = leftSum + rightSum + val;
                    curMax = max(curMax, total);
                }
                dp[i][j] = curMax;
                // cout << "dp[" << i << "][" << j << "]" << " = " << curMax << endl; 
            }
        }
        
        // _print(dp);
        
        return dp[0][n-1];
        
    }
};