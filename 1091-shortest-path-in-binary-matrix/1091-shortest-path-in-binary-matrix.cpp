class Solution {
    
    int solveBFS(vector<vector<int>>& grid){
        
        int size = grid.size();
        
        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int count = 1, i, j;
        
        
        while(!q.empty()){
            pair<int, int> curr_idx = q.front();
            q.pop();
            i = curr_idx.first, j = curr_idx.second;
            if(curr_idx.first == size - 1 and curr_idx.second == size - 1){
                // cout << endl;
                // for(int i = 0; i < grid.size(); i++){
                //     for(int j = 0; j < grid.size(); j++){
                //         cout << grid[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                return grid[i][j];
            } 
            
            // cout << "i: " << i << " j: " << j << endl;
            
            if(i>0 and j > 0 and grid[i-1][j-1] == 0){
                // cout << "\ttop left" << endl;
                q.push({i-1, j-1}); // top left
                grid[i-1][j-1] = grid[i][j] + 1;
            } 
            
            if(i>0 and grid[i-1][j] == 0){
                // cout << "\tup" << endl;
                q.push({i-1, j}); // up
                grid[i-1][j] = grid[i][j] + 1;
            } 
            
            if(i>0 and j < grid[0].size()-1 and grid[i-1][j+1] == 0){
                // cout << "\ttop right" << endl;
                grid[i-1][j+1] = grid[i][j] + 1;
                q.push({i-1, j+1}); // top right
            }
            if(j < grid[0].size()-1 and grid[i][j+1] == 0){
                // cout << "\tright" << endl;
                q.push({i, j+1}); // right
                grid[i][j+1] = grid[i][j] + 1;
            } 
            if(i < grid.size()-1 and j < grid[0].size()-1 and grid[i+1][j+1] == 0){
                // cout << "\tbottom right" << endl;
                grid[i+1][j+1] = grid[i][j]+1;
                q.push({i+1, j+1}); // bottom right
            } 
            if(i< grid.size()-1 and grid[i+1][j] == 0){
                // cout << "\tdown" << endl;
                grid[i+1][j] = grid[i][j] + 1;
                q.push({i+1, j}); // down
            } 
            if(i < grid.size()-1 and j > 0 and grid[i+1][j-1] == 0){
                // cout << "\tbottom left" << endl;
                q.push({i+1, j-1}); // bottom left
                grid[i+1][j-1] = grid[i][j] + 1;
            } 
            if(j > 0 and grid[i][j-1] == 0){
                // cout << "\tleft" << endl;
                q.push({i, j-1}); // left
                grid[i][j-1] = grid[i][j] + 1;
            } 
            
        
        }
        
        // if(i == size - 1 and j == size - 1){
        //         cout << endl;
        //         for(int i = 0; i < grid.size(); i++){
        //             for(int j = 0; j < grid.size(); j++){
        //                 cout << grid[i][j] << " ";
        //             }
        //             cout << endl;
        //         }
        //         return grid[i][j];
        //     } 
        
        return -1;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        return solveBFS(grid);
    }
};