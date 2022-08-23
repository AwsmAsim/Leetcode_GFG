class Solution {
    
    void DFS(int i, unordered_set<int>& visited, vector<vector<int>>& rooms){
        
        visited.insert(i);
        
        for(int nbr: rooms[i]){
            if(visited.find(nbr)==visited.end()){
                DFS(nbr, visited, rooms);
            }
        }
        
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        DFS(0, visited, rooms);
        // cout << visited.size() << endl;
        return visited.size() == rooms.size();
    }
};