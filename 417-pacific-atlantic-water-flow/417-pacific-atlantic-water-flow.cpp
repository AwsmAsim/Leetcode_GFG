class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        // 2D matrix for pacific & atlantic and initialised with 0 
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));
        
        // updated the pacific and atlantic matrix cells from which water can flow to respective oceans
        for(int i=0; i<heights[0].size(); i++){
                dfs(heights, 0 , i,INT_MIN, pacific);
                dfs(heights, heights.size()-1 , i, INT_MIN, atlantic);
        }
        for(int i=0; i<heights.size(); i++){
                dfs(heights, i, 0 ,INT_MIN, pacific);
                dfs(heights, i, heights[0].size()-1 ,INT_MIN, atlantic);
        }
        
        // intersection of pacific and atlantic matrix
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pacific[i][j]==-1 && atlantic[i][j]==-1)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean ){
        if(i < 0 || j < 0 || i >=heights.size() || j >=heights[0].size()) return;
        
        //water can flow from height less than or equal to 
        if(heights[i][j]<prev) return;
        
        //if cell is already visited
        if(ocean[i][j]==-1) return ;
        
        //mark the cell as visited
        ocean[i][j]= -1;
        
        dfs(heights, i-1, j, heights[i][j], ocean); //up
        dfs(heights, i+1, j, heights[i][j], ocean); //down 
        dfs(heights, i, j-1, heights[i][j], ocean); //left
        dfs(heights, i, j+1, heights[i][j], ocean); //right
    }
};