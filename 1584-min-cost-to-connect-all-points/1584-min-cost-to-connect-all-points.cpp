class Solution {
    
    void printArray(int arr[], int n){
        for(int i = 0; i < n; i++) cout << i << ": "<< arr[i] << ", ";
        cout << endl;
    }
    
    int getDist(int x1, int x2, int y1, int y2){
        return (abs(x2-x1) + abs(y2-y1));
    }
    
    void printGraph(vector<pair<int, int>> graph[]){
        for(int i = 0; i <= graph->size(); i++){
            cout << i << ": {";
            for(auto edge: graph[i])
                cout << "("<< edge.first << ", " << edge.second << "), ";
            cout << "}" << endl;
        }
    }
    
    struct Compare{
        bool operator()(const pair<int, int> p1, const pair<int, int> p2){
            if(p1.second == p2.second){
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        }
    };
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> g_points;
        int node = 0, dist;
        
        for(auto point: points){
            g_points[node] = point;
            ++node;
        }
        
        vector<pair<int, int>> graph[points.size()];
        for(int i = 0; i < points.size(); i++){
            int x1 = g_points[i][0], y1 = g_points[i][1];
            for(int j = 0; j < points.size(); j++){
                if(i==j) continue;
                int x2 = g_points[j][0], y2 = g_points[j][1];
                dist = getDist(x1, x2, y1, y2);
                graph[i].push_back({j, dist});
            }
        }
        
        // printGraph(graph);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        pq.push({0, 0});
        // for(int i = 1; i < points.size(); i++){
        //     pq.push({i, INT_MAX});
        // }
        
        // cout << pq.top().first << endl;
        int N = points.size();
        int key[N], parent[N], mstSet[N];
        
        for(int i = 0; i<N; i++){
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        
        key[0] = 0;
        parent[0] = -1;
        // mstSet[0] = 1;
        
        for(int i = 0; i < points.size()-1; i++){
            int u = pq.top().first;
            while(mstSet[u]==true){
                pq.pop();
                u = pq.top().first;
            }
            // cout << u << endl;
            pq.pop();
            
            mstSet[u] = true;
            
            for(auto it: graph[u]){
                int v = it.first;
                int weight = it.second;
                if(mstSet[v]==false and weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({v,key[v]});
                }
            }
            // printArray(key, N);
        }
        
        int sum1 = 0;
        for(int i = 0; i < N; i++) sum1 += key[i];
        
        
        return sum1;
    }
};