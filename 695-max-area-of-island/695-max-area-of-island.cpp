class Solution {
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0) return 0;
        if(i >= m || j >= n) return 0;
        if(grid[i][j] == 0) return 0;
        
        grid[i][j]=0;
        return (1+dfs(i-1, j, grid)+
                dfs(i+1, j, grid)+
                dfs(i, j+1, grid)+
                dfs(i, j-1, grid)
                );
    }
    
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxValue = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==1)
                maxValue = max(dfs(i, j, grid), maxValue);
            }
        }
        return maxValue;
    }
};