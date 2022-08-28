class Solution {
    
    int n, m;
    vector<vector<int>> mat;
    
    void sortDiagonal(int i, int j){
        vector<int> temp;
        int initialI = i, initialJ = j, idx = 0;
        while(i < n and j < m){
            temp.push_back(mat[i][j]);
            ++i;
            ++j;
        }
        
        sort(temp.begin(), temp.end());
        
        // for(int num: temp) cout << num << ", ";
        // cout << endl;
        
        
        i = initialI, j = initialJ;
        
        while(idx < temp.size()){
            // cout << "mat["<<i<<"]["<<j<<"]" << " = " << temp[idx] << endl;
            mat[i][j] = temp[idx];
            ++i;++j;++idx;
        }
    }
    
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        this->m = mat[0].size(), this->n = mat.size(), this->mat = mat;
        
        // traverse first row --> [0][i]
        for(int i = 0; i < m; i++){
            sortDiagonal(0, i);
        }
        
        // traverse first column from row 1
        for(int i = 1; i < n; i++){
            sortDiagonal(i, 0);
        }
        
        return this->mat;
        
    }
};