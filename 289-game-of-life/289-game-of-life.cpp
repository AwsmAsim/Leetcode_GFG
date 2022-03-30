class Solution {
    
    int checkNeighbour(vector<vector<int>>& board, int i, int j){
        int number = board[i][j];
        int n = board.size();
            int count = 0;
            // up
            if(i>0 and board[i-1][j]==1){
                ++count;
            }
            // left
            if(j>0 and board[i][j-1] == 1){
                ++count;
            }
            // top-left
            if(i>0 and j > 0 and board[i-1][j-1] == 1){
                ++count;
            }
            // bottom-left
            if(i < board.size()-1 and j > 0 and board[i+1][j-1]==1){
                ++count;
            }
            // down
            if(i < board.size()-1 and board[i+1][j] == 1){
                ++count;
            }
            // bottom-right
            if(i < board.size()-1 and j < board[0].size()-1 and board[i+1][j+1] == 1){
                ++count;
            }
            //right
            if(j < board[0].size()-1 and board[i][j+1] == 1){
                ++count; 
            }
            // top-right
            if(i > 0 and j < board[0].size()-1 and board[i-1][j+1]){
                count++;
            }
        // cout << count << endl;
        if(board[i][j] == 1){
            if(count == 2 || count == 3) return 1;
        }else{
            if(count == 3) return 1;
        }
        return 0;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board1 = board;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] = checkNeighbour(board1, i, j);
            }
        }
    }
};