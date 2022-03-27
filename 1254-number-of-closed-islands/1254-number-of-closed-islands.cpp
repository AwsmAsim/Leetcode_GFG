class Solution {
    
    void printList(vector<vector<int>>& grid){
        for(auto row: grid){
            cout << "[";
            for(auto a: row) cout << a << ", ";
            cout << "], " << endl;
        }
    }
    
    void convert(int i, int j, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0) return;
        if(i >= m || j >= n) return;
        if(grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        return;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0) return;
        if(i >= m || j >= n) return;
        if(grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        return;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1 ){
                    if(grid[i][j]==0){
                        convert(i, j, grid);
                    }
                }
            }
        }   
        
        // printList(grid);
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==0){
                    // cout << i << " " << j << ", ";
                    dfs(i, j, grid);
                    ++count;
                }
            }
        }
        
        // cout << endl;
        // printList(grid);
        return count;
    }
};