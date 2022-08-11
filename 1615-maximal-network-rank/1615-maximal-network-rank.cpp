class Solution {
public:
    
    bool find(vector<int> edges, int n){
        for(int edge: edges){
            if(edge == n) return true;
        }
        return false;
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> graph[n];
        
        for(vector<int> edge: roads){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int MNR = 0;
        for(int i = 0; i < n; i++){
            int edgeCount1 = graph[i].size();
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                int edgeCount2 = graph[j].size();
                int network = edgeCount1 + edgeCount2;
                if(find(graph[i], j)) --network;
                // cout << i << "-" << j << " -> " << network << endl;  
                MNR = max(MNR, network);
            }
        }
        
        return MNR;
        
        
    }
};