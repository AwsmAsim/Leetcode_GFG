class Solution {
    
    bool dfs(int i, vector<int>& visited, vector<int>& recV, vector<int> graph[]){
        visited[i] = 1, recV[i] = 1;
        
        for(int nbr: graph[i]){
            if(!visited[nbr]){
                if(dfs(nbr, visited, recV, graph)) return true;
            }else{
                if(recV[nbr]) return true;
            }
        }
        
        recV[i] = 0;
        return false;
    }
    
    bool detectCycle(int V, vector<int> graph[]){
        vector<int> visited(V, 0);
        vector<int> recV(V, 0);
        
        for(int i = 0; i < V; ++i){
            if(!visited[i]){
                if(dfs(i, visited, recV, graph)) return true;
            }
        }
        
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        
        for(vector<int> req: prerequisites){
            int u = req[0];
            int v = req[1];
            graph[u].push_back(v);
        }
        
        if(detectCycle(numCourses, graph)) return false;
        return true;
        
    }
};