class Solution {
    
    void convert(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0) return;
        if(i>=grid.size() or j >= grid[0].size()) return;
        if(grid[i][j]==0) return;
        // cout << i << " " << j << endl;
        grid[i][j] = 0;
        convert(grid, i+1, j);
        convert(grid, i-1, j);
        convert(grid, i, j+1);
        convert(grid, i, j-1);
    }
    void dfs(vector<vector<int>>& grid, int& count, int i, int j){
        if(i < 0 || j < 0) return;
        if(i>=grid.size() or j >= grid[0].size()) return;
        if(grid[i][j]==0) return;
        grid[i][j] = 0;
        ++count;
        dfs(grid, count, i+1, j);
        dfs(grid, count, i-1, j);
        dfs(grid, count, i, j-1);
        dfs(grid, count, i, j+1);
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // cout << grid[0][8];
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i==0 or j==0 or i == (int)grid.size()-1 or j == grid[0].size()-1){
                    // cout << endl;
                    // cout << i << j << endl;
                    if(grid[i][j] == 1) convert(grid, i, j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==1){
                    dfs(grid, count, i, j);
                }
            }
        }
        // for(auto row: grid){
        //     for(auto a: row) cout << a << " ";
        //     cout << endl;
        // }
        return count;
    }
};