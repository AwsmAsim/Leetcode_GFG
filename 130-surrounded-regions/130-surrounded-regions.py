class Solution:
    
    def dfs(self, x, y, board, answerBoard):
        
        if (x < 0) or (x >= len(board)) or (y<0) or (y >= len(board[0])): return None 
        # print(x ,y)
        if board[x][y] == 'X' or answerBoard[x][y] == 'O':
            return None
        answerBoard[x][y] = 'O'
        
        directions = [[0,1], [1,0], [0, -1], [-1, 0]]
        
        for direction in directions:
            self.dfs(x + direction[0], y + direction[1], board, answerBoard)
            
        
    
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])
        answerBoard = [['' for i in range(m)] for i in range(n)]
        for i in range(0,n):
            # print('board[{ii}][{j}] = {ans}'.format(ii=i, j = 0, ans = board[i][0]))
            # print('board[{ii}][{j}] = {ans}'.format(ii=i, j = n-1, ans = board[i][n-1]))
            if board[i][0] == 'O':
                self.dfs(i, 0, board, answerBoard)
            if board[i][m-1] == 'O':
                # print('here')
                self.dfs(i, m-1, board, answerBoard)
        
        # print(answerBoard)
        
        for i in range(0,m):
            # print('board[{ii}][{j}] = {ans}'.format(ii=i, j = 0, ans = board[i][0]))
            # print('board[{ii}][{j}] = {ans}'.format(ii=i, j = n-1, ans = board[i][n-1]))
            if board[0][i] == 'O':
                self.dfs(0, i, board, answerBoard)
            if board[n-1][i] == 'O':
                self.dfs(n-1, i, board, answerBoard)
                
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and answerBoard[i][j] != 'O':
                    board[i][j] = 'X'
        