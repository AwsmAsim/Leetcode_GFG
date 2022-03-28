class Solution {
    
    void dfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1, int i, int j, int& flag){
        if(i < 0 || j < 0 || i >= grid2.size() || j>=grid2[0].size() || grid2[i][j] == 0) return;
        if(grid1[i][j]==0) flag = 0;
        // cout << i << " " << j << endl;
        grid2[i][j] = 0;
        dfs(grid2, grid1, i+1, j, flag);
        dfs(grid2, grid1, i-1, j, flag);
        dfs(grid2, grid1, i, j+1, flag);
        dfs(grid2, grid1, i, j-1, flag);
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0, flag = 1;
        for(int i = 0; i < grid1.size(); i++){
            for(int j = 0; j < grid1[0].size(); j++){
                if(grid2[i][j] == 1){
                    flag = 1;
                    // cout << i << " " << j << " " << grid1[i][j] << endl;
                    dfs(grid2, grid1, i, j, flag);
                    count += flag;
                }
            }
        }
        return count;
    }
};