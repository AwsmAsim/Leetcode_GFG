class Solution {
    
    int getMaxPath(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp){
        int n = matrix.size(), m = matrix[0].size();
        
        // // if(printi){
        //     // cout << "m: " << m << " n: " << n << endl;
        // // }
        if(dp[x][y]!=-1) return dp[x][y];
        if(x < 0 or x >= n) return 0;
        if(y < 0 or y >= m) return 0;
            
        // cout << x << " " << y << endl;
        
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        
        int max1 = 0;
        for(auto direction: directions){
                if(x+direction[0] < 0 or x+direction[0] >= n or y+direction[1] <0 or y + direction[1]>=m ) continue;
                if(matrix[x+direction[0]][y+direction[1]] > matrix[x][y] )
                    max1 = max(max1, getMaxPath(matrix, x+direction[0], y+direction[1], dp));
        }
        
        dp[x][y] = max1 + 1;
        return dp[x][y];
        
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
        
        int max1 = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                // int answer = getMaxPath(matrix, i, j);
                max1 = max(max1, getMaxPath(matrix, i, j, dp));
                // cout << '\n'<< answer << " -> answer " << endl; 
            }
        }
        
        return max1;
    }
};