class Solution {
    
    int tabulation(int row, int col){
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] =1;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; j++){
                if(i == 0 or j == 0) dp[i][j] = 1;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        // for(vector<int> row: dp){
        //     for(int a : row) cout << a << ", ";
        //     cout << endl;
        // }
        
        return dp.back().back();
    }
    
    int findPaths1(int row, int col){
        
        // invalid operation
        if(row < 0 or col < 0) return 0;
        if(row == 0 and col == 0) return 1;
        
        int left, up;
        left = findPaths1(row, col-1);
        up = findPaths1(row - 1, col);
        
        return left + up;
    }
    
    int findPaths(int x, int y, vector<vector<int>>& dp){
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        if(x==0 && y==0){
            return 1;
        }
        
        int count = 0;
        if(x > 0)
        count += findPaths(x-1, y, dp);
        
        if(y>0)
        count += findPaths(x, y-1, dp);
        dp[x][y] = count;
        return dp[x][y];
    }
    
public:
    int uniquePaths(int m, int n) {
        return tabulation(m, n);
        return findPaths1(m-1, n-1);
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return findPaths(m-1, n-1, dp);
    }
};