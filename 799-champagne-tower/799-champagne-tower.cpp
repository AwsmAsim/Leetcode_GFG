class Solution {
    
    void printDp(vector<vector<double>>& dp){
        cout << endl;
        for(auto rows: dp){
            for(auto a: rows) cout << a << ", ";
            cout << endl;
        }
        cout << endl;
    }
    
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1, vector<double>(query_row+1, 0));
        dp[0][0] = (double)poured;
        for(int i = 1; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                
                if(j==0){
                    if(dp[i-1][j] > 1)
                    dp[i][j] = (dp[i-1][j] - 1)/2;
                }else 
                    if(j==i){
                    
                    if(dp[i-1][j-1] > 1)
                    dp[i][j] = (dp[i-1][j-1]-1)/2;
                }
                
                else
                {
                    
                    if(dp[i-1][j-1] > 1 and dp[i-1][j] > 1)
                    dp[i][j] = (dp[i-1][j-1]-1)/2 + (dp[i-1][j]-1)/2;
                    
                    else if(dp[i-1][j-1] > 1) dp[i][j] = (dp[i-1][j-1]-1)/2;
                    
                    else if((dp[i-1][j])>1) dp[i][j] = (dp[i-1][j]-1)/2;
                }
            }
        }
        
        // printDp(dp);
        
//         cout << query_row << " " << query_glass << endl;
        if(dp[query_row][query_glass] >= 1) return 1;
        return dp[query_row][query_glass];
        // return 0;
    }
};