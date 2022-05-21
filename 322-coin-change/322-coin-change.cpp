class Solution {
    
    
    int solveDP(int idx, int leftAmount, vector<int>& coins, vector<vector<int>>& dp){
        
        if(dp[idx][leftAmount] != -1) return dp[idx][leftAmount];
        
        if(leftAmount == 0) return 0;
        if(idx == coins.size()){
            return 100000;
        }
        
        int pick = INT_MAX, non_pick = INT_MAX;
        if(coins[idx]<=leftAmount)
            pick = 1 + solveDP(idx, leftAmount - coins[idx], coins, dp);
        non_pick = solveDP(idx + 1, leftAmount, coins, dp);
        
        dp[idx][leftAmount] = min(pick, non_pick);
        return dp[idx][leftAmount];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount +1, -1));
        int ans = solveDP(0, amount, coins, dp);
        if(ans>10000) return -1;
        else return ans;
    }
};