class Solution {
    
    bool findWord(vector<vector<char>>& board, string word, int ptr, int i, int j){
        if(ptr == word.size()) return true;
        if(i<0 or j < 0 or i >= board.size() or j >= board[0].size()) return false;
        if(board[i][j] == word[ptr]){
            ++ptr;
            if(ptr >= word.size()) return true;
            char initial_value = board[i][j];
            board[i][j] = '1';
            if(findWord(board, word, ptr, i+1, j))
                return true;
            if(findWord(board, word, ptr, i-1, j))
                return true;
            if(findWord(board, word, ptr, i, j+1))
                return true;
            if(findWord(board, word, ptr, i, j-1))
                return true;
            --ptr;
            board[i][j] = initial_value;
            return false;
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(findWord(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};