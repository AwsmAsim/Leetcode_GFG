class Solution {
    
    void dfs(int currentColor, int newColor, int i, int j, vector<vector<int>>& image){
        int m = image.size(), n = image[0].size();
        // cout << "m: " << m << " n: " << n  << " i: " << i << " j: "<<j << endl;
        if(i<0 or j < 0) return;
        if(i >= m or j >= n) return;
        if(image[i][j] != currentColor)
            return;
        image[i][j] = newColor;
        dfs(currentColor, newColor, i-1, j, image);
        dfs(currentColor, newColor, i+1, j, image);
        dfs(currentColor, newColor, i, j+1, image);
        dfs(currentColor, newColor, i, j-1, image);
        return;
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rowSize = image.size(), colSize = image[0].size();
        if(newColor!=image[sr][sc])
        dfs(image[sr][sc], newColor, sr, sc, image);
        return image;
    }
};