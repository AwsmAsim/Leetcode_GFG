class Solution {
    
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0) return;
        if(i >= m || j >= n) return;
        if(grid[i][j] == '0') return;
        if(visited[i][j] == 1) return;
        visited[i][j] = 1;
        
        dfs(i+1, j, visited, grid);
        dfs(i-1, j, visited, grid);
        dfs(i, j+1, visited, grid);
        dfs(i, j-1, visited, grid);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] and grid[i][j]!='0'){
                    dfs(i, j, visited, grid);
                    ++count;
                }
            }
        }
        
        return count;
    }
};