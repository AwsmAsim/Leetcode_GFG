class Solution {
    
    void dfs(int i, int j){
        if(i < 0 or j < 0 or i >= n or j >= m) return;
        if(Grid[i][j] == '0') return;
        Grid[i][j] = '0';
        
        vector<vector<int> > directions = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}  
        };  
        
        for(vector<int> direction: directions){
            dfs(i + direction[0], j + direction[1]);
        }
    }
    
public:
    int n, m;
    vector<vector<char>> Grid;
    int numIslands(vector<vector<char>>& grid) {
        this-> n = grid.size();
        this-> m = grid[0].size();
        Grid = grid;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(Grid[i][j] == '1'){
                    dfs(i,j);    
                    ++count;
                }
            }
        }
        
        return count;
    }
};