class Solution {
    
    int getMaxProfit(vector<int>& prices, int idx, int sell, int moves, vector<vector<vector<int>>>& dp){
        
        if(dp[idx][sell][moves] != -1) return dp[idx][sell][moves];
        
        if(moves == 0) return 0;
        
        if(idx == prices.size()) return 0;
        
        int profit1 = 0, profit2 = 0;
        if(sell){
            profit1 = getMaxProfit(prices, idx + 1, !sell, moves - 1, dp) + prices[idx];
            profit2 = getMaxProfit(prices, idx + 1, sell, moves, dp);
        }else{
            profit1 = getMaxProfit(prices, idx + 1, !sell, moves, dp) - prices[idx];
            profit2 = getMaxProfit(prices, idx + 1, sell, moves, dp);
        }
        
        dp[idx][sell][moves] = max(profit1, profit2);
        return dp[idx][sell][moves];
    }
    
    
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), buySell = 2, moves = 2;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(buySell, vector<int>(moves + 1, -1)));
        
        return getMaxProfit(prices, 0, 0, 2, dp);
    }
};