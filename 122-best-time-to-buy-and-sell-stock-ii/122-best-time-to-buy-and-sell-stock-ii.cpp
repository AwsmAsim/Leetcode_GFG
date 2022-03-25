class Solution {
    
    int solve(int idx, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        
        if(dp[buy][idx]!=-1) return dp[buy][idx];
        
        if(idx == prices.size()){
            return 0;
        }
        int profit1, profit2;
        if(buy){
            profit1 = solve(idx + 1, !buy, prices, dp) - prices[idx];
            profit2 = solve(idx + 1, buy, prices, dp);
        }else{
            profit1 = solve(idx + 1, !buy, prices, dp) + prices[idx];
            profit2 = solve(idx + 1, buy, prices, dp);
        }
        
        dp[buy][idx] = max(profit1, profit2);
        return dp[buy][idx];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1, -1));
        int mProfit = solve(0, 1, prices, dp);
        return mProfit;
    }
};