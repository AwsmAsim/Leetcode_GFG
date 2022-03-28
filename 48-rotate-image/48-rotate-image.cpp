class Solution {
    
    void printList1D(vector<int> lst){
        cout << endl;
        cout << "[";
        for(auto a: lst) cout << a << ", ";
        cout << "]" << endl;
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int j = 0; j < matrix.size(); j++){
            for(int i = 0; i < matrix.size()/2; i++){
                swap(matrix[j][i],matrix[j][matrix.size()-1-i]);
            } 
        }
        
    }
};