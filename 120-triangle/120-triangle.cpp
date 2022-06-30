class Solution {
    
    int recursive(vector<vector<int>>& triangle, int row, int col){
        
        if(row == triangle.size()) return 0;
        
        return min(triangle[row][col] + recursive(triangle,row + 1,col), triangle[row][col] + recursive(triangle,row + 1,col + 1));
        
    }
    
    
    int BottomUp(vector<vector<int>>& triangle){
        
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        dp[0][0] = triangle[0][0];
        
        for(int row = 1; row < triangle.size(); ++row){
            for(int col = 0; col <= row; ++col){
                int i = row, j = col;
                if(col == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if(col == row){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else
                dp[i][j] = min(dp[i-1][j] + triangle[i][j], dp[i-1][j-1] + triangle[i][j]);
            }
        }
        
//         // DP
//         for(vector<int> row: dp){
//             for(int val: row) cout << val << ", ";
//             cout << endl;
//         }
        
        int ans = INT_MAX; 
        for(int i = 0; i < dp.size(); ++i){
            ans = min(ans, dp[dp.size()-1][i]);
            // cout << "ans: " << ans << endl;
        }
        return ans;
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return BottomUp(triangle);
        return recursive(triangle, 0, 0);
    }
};