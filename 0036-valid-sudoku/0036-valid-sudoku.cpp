class Solution {
    
    int getBlockNo(int i, int j){
        if(i <= 2){
            if(j<=2) return 0;
            else if(j<= 5) return 1;
            else return 2;
        }
        if(i <= 5){
            if(j<=2) return 3;
            else if(j<= 5) return 4;
            else return 5;
        }
        else{
            if(j<=2) return 6;
            else if(j<= 5) return 7;
            else return 8;
        }
        return -1;
    }
    
    void _print(vector<vector<int>> grid){
        
        for(vector<int> row: grid){
            for(int a: row) cout << a << ", ";
            cout << endl;
        }
        
    }
    
    void _print(vector<int> arr){
        for(int num: arr) cout << num << ", ";
        cout << endl;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> nums(9,-1);
        
        // Check columns
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                // cout << "Did not overlow in column traversal" << i << " " << j  << endl;
                if(nums[board[i][j] - '1'] == i) return false;
                nums[board[i][j] - '1'] = i;
            }
        }
        
        for(int i = 0; i < 9; i++) nums[i] = -1;
        // Check rows
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                // cout << "Did not overlow in row traversal" << j << " " << i << endl;
                if(nums[board[j][i] - '1'] == i) return false;
                nums[board[j][i] - '1'] = i;
            }
            // _print(nums);
        }
        
        vector<vector<bool>> blockNum(9, vector<bool>(9, 0));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                // cout << "Did not overlow" << endl;
                int blockk = getBlockNo(i, j); 
                // cout << "blockNO: " << blockk << endl;
                if(blockNum[blockk][board[i][j] - '1']) return false;
                blockNum[blockk][board[i][j] - '1'] = true;
                                 
            }
        }
                                 
                                 
        return true;
    }
};