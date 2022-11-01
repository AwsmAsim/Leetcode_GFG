class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& grid){
        
        // cout << i << " " << j << endl;
        int m = grid.size(), n = grid[0].size();
        if(j == 0 and grid[i][j] == -1) return -1;
        if(j == n-1 and grid[i][j] == 1) return -1;
        if(grid[i][j] == 1 and j < n-1 and grid[i][j + 1] == -1) return -1;
        if(grid[i][j] == -1 and j > 0 and grid[i][j - 1] == 1) return -1;
        if(i == m-1 and grid[i][j] == 1) return j+1;
        if(i == m-1 and grid[i][j] == -1) return j-1;
        
        if(grid[i][j] == 1) return solve(i + 1, j + 1, grid);
        if(grid[i][j] == -1) return solve(i + 1, j - 1, grid);
        
        return -1;
    }
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        // Incase current is 1, right should't be -1,
        // Incase current is -1, left shouldn't be 1
        // For col == 0, current shouldn't be -1
        // For col == n-1 current shouldn't be 1
        
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++){
            // cout << "For Col " << i << endl;
            int cAns = solve(0, i, grid);
            ans[i] = cAns;
        }
        
        return ans;
        
    }
};