class Solution {
public:
    
    int entranceI, entranceJ;
    
    bool isInValidCell(int i, int j, vector<vector<char>>& maze){
        if(i < 0 or j < 0 or i >= maze.size() or j >= maze[0].size()) return true;
        if(maze[i][j] == '+') return true;
        return false;
    }
    
    bool isBorder(int i, int j, vector<vector<char>>& maze){
        if( i == 0 or j == 0 or i == maze.size() - 1 or j == maze[0].size()-1) return true;
        return false;
    }
    
    int findExit(int i, int j, vector<vector<char>>& maze){
        
        // cout << i << " " << j << endl;
        if(isInValidCell(i, j, maze)) return INT_MAX;
        if(!(i == entranceI and j==entranceJ) and isBorder(i,j,maze)) return 0;
        maze[i][j] = '+';
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int curScore = INT_MAX;
        
        for(vector<int> direction: directions){
            int tAns = findExit(i + direction[0], j + direction[1], maze);
            // cout << "tAns: " << tAns << endl;
            if(tAns == INT_MAX) continue;
            curScore = min(curScore, tAns);
            // cout << curScore << endl;
        }
        
        if(curScore == INT_MAX) return INT_MAX;
        return ++curScore;
    }
    
    int findExitBFS(int i, int j, vector<vector<char>>& maze){
        queue<vector<int>> Q;
        Q.push({i, j, 0});
        int score = 0;
        bool found = false;
        
        while(!Q.empty()){
            vector<int> topNode = Q.front();
            Q.pop();
            
            i = topNode[0], j = topNode[1], score = topNode[2];
            if(isInValidCell(i, j, maze)) continue;
            if(!(i == entranceI and j==entranceJ) and isBorder(i,j,maze)){
                found = true;
                break;
            } 
            maze[i][j] = '+';
            
            vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
            int curScore = INT_MAX;

            for(vector<int> direction: directions){
                Q.push({i + direction[0], j + direction[1], score + 1});
            }
        }
        if(found == false) return -1;
        return score;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        entranceI = entrance[0], entranceJ = entrance[1];
        
        int ans = findExitBFS(entranceI, entranceJ, maze);
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};