class Solution {
public:
    
    unordered_set<int> indexSet, leftDiagonals, rightDiagonals;
    
    bool isValid(int i, int j, int n){
        if(indexSet.find(j)!=indexSet.end()) return false;
        if(leftDiagonals.find(i+j)!=leftDiagonals.end()) return false;
        if(rightDiagonals.find(i-j)!=rightDiagonals.end()) return false;
        return true;
        
    }
    
    void getPositions(int i, int n, vector<int>& answer, vector<vector<int>>& answers){
        
        if(i >= n){
            if(answer.size()==n) answers.push_back(answer);
            return;
        };
        
        for(int j = 0; j < n; j++){
            if(isValid(i,j, n)){
                // cout << "(" << i << "," << j << ") is valid." << endl;
                indexSet.insert(j);
                leftDiagonals.insert(i+j);
                rightDiagonals.insert(i-j);
                
                // for(auto a: leftDiagonals) cout << a << ", ";
                // cout << endl;
                // for(auto a: rightDiagonals) cout << a << ", ";
                // cout << endl;
                
                
                answer.push_back(j);
                getPositions(i + 1, n, answer, answers);
                answer.pop_back();
                indexSet.erase(j);
                leftDiagonals.erase(i+j);
                rightDiagonals.erase(i-j);
            }
        }
        
        return;
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> answers;
        vector<int> answer;
        
        getPositions(0, n, answer, answers);
        
        
        vector<vector<string>> finalAnswers;
        for(auto v: answers){
            vector<string> matrix;
            for(auto col: v){
                string row;
                
                for(int i = 0; i < n; ++i){
                    
                    if(i==col) row.push_back('Q');
                    else row.push_back('.');
                }
                
                matrix.push_back(row);
            }
            finalAnswers.push_back(matrix);
        }
        
        return finalAnswers;
        
        
    }
};