class Solution {
public:
    
    bool isValid(int i, vector<vector<int>>& matrix){
        
        int n = matrix.size(), m = matrix[0].size();
        int j = 0, num = matrix[0][i];
        
        while(i < m and j < n){
            if(matrix[j][i] != num) return false;
            ++i;
            ++j;
        }
        
        return true;
    }
    
    bool isValid2(int i, vector<vector<int>>& matrix){

        int n = matrix.size(), m = matrix[0].size();
        int j = 0, num = matrix[i][0];
        
        while(i < n and j < m){
            if(matrix[i][j] != num) return false;
            ++i; 
            ++j;
        }
        
        return true;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        // Traverse diagonals from row 0, all columns in row 0
        for(int i = 0; i < m; i++){
            if(!isValid(i, matrix)) return false;
        }
        
        // Traverse diagonals from col 1
        for(int i = 1; i < n; i++){
            if(!isValid2(i, matrix)) return false;
        }
        
        
        return true;
    }
};