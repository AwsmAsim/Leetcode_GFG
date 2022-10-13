class Solution {
    
    int dfs(int i , int j, vector<vector<int> >& grid, vector< vector<int> >& dp){
        
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size()) return INT_MAX;
        if(i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        
        int right = dfs(i, j+1, grid, dp);
        int left = dfs(i+1, j, grid, dp);
        
        if(right == INT_MAX and left == INT_MAX) return INT_MAX;
        return dp[i][j] = (grid[i][j] + min(right, left));
    }
    
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector< vector<int> > dp(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(0,0,grid, dp);
    }
};