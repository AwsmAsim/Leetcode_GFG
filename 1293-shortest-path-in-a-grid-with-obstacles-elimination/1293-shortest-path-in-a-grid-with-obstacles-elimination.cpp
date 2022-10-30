class Solution {
public:
    
    bool invalid(int i, int j, int k, int n, int m, vector<vector<vector<int>>>& visited){
        if(i < 0 or j < 0 or i >= n or j >= m) return true;
        // cout << i << " " << j  << endl;
        if(visited[i][j][k]) return true;
        return false;
    }
    
    int solve(int i, int j, vector<vector<int>>& grid, int k){
        
        int n = grid.size(), m = grid[0].size();
        // cout << "n: " << n << " m: " << m << " k: " << k << endl;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        queue<vector<int>> Q;
        
        Q.push({i, j, k, 0});
        int ans = INT_MAX;
        
        while(!Q.empty()){
            
            vector<int> topNode = Q.front();
            Q.pop();
            i = topNode[0], j = topNode[1];
            int moves = topNode[3], skips = topNode[2];
            
            // cout << i << " " << j << " " << moves << endl;
            
            if(invalid(i, j, skips, n, m, vis)) continue;
            vis[i][j][skips] = 1;
            if(grid[i][j] == 1){
                if(skips>0)
                --skips;
                else continue;
            } 
            if(i == n-1 and j == m-1) return moves;
            
            // cout << i << " " << j << " " << moves << endl;
            
            
            for(vector<int> direction: directions){
                Q.push({i + direction[0], j+direction[1], skips, moves + 1});
            }
            
        }
        
        // cout << "  --> " << i << " " << j << "->" << ans << endl;
        return ans;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int ans = solve(0,0, grid, k);
        if(ans < 0 or ans == INT_MAX) return -1;
        return ans;
    }
};