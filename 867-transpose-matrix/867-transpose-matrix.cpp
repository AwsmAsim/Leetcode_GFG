class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rowSize = matrix.size(), columnSize = matrix[0].size();
        vector<vector<int>> outputMatrix(columnSize, vector<int>(rowSize, 0));
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < columnSize; ++j){
                outputMatrix[j][i] = matrix[i][j];
            }
        }
        
        return outputMatrix;
    }
};