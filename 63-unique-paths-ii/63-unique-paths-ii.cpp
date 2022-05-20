class Solution {
    
    int solveDP(vector<vector<int>>& grid){
        vector<vector<int>> ansGrid(grid.size(), vector<int>(grid[0].size(), 0));
        
        ansGrid[0][0]=1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if( i == 0 and j == 0) continue;
                if(i==0){
                    if(grid[i][j]==1) ansGrid[i][j] = 0;
                    else ansGrid[i][j] = ansGrid[i][j-1];
                }else if(j==0){
                    if(grid[i][j]==1) ansGrid[i][j] = 0;
                    else ansGrid[i][j] = ansGrid[i-1][j];
                }
                else{
                    if(grid[i][j]==1) ansGrid[i][j] = 0;
                    else ansGrid[i][j] = ansGrid[i-1][j] + ansGrid[i][j-1];
                }
            }
        }
        
        return ansGrid[ansGrid.size()-1][ansGrid[0].size()-1];
    }
    
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        return solveDP(obstacleGrid);
    }
};