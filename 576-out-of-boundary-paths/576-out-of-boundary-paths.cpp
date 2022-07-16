class Solution {
    
    
    int movedRight = 1, movedLeft = 2, movedUp = 3, movedDown = 4;
    int mod = 1000000007;
    
    
    int recursive(int m, int n, int maxMove, int startRow, int startColumn, int recentMove,
                 vector<vector<vector<long long>>>& dp){
        
        if(maxMove < 0 ) return 0;
        if(startRow < 0 or startColumn < 0 or startRow >= m or startColumn >= n) return 1;
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        
        long long down = 0, right = 0, up = 0, left = 0;
        
        if(recentMove != movedDown)
        up = recursive(m, n, maxMove - 1, startRow - 1, startColumn, up, dp);
        
        if(recentMove != movedUp)
        down = recursive(m, n, maxMove - 1, startRow + 1, startColumn, down, dp);
        
        if(recentMove!= movedRight)
        right = recursive(m, n, maxMove - 1, startRow, startColumn + 1, right, dp);
        
        if(recentMove != movedLeft)
        left = recursive(m, n, maxMove - 1, startRow, startColumn - 1, left, dp);
        
        dp[startRow][startColumn][maxMove] = ((up%mod) + (down%mod) + (right%mod) + (left%mod))%mod;
        return dp[startRow][startColumn][maxMove];
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(m, 
                            vector<vector<long long>>(n, vector<long long>(maxMove + 1, -1)));
        return recursive(m, n, maxMove, startRow, startColumn, 5, dp);
    }
};