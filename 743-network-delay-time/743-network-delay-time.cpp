class Solution {
    
    class Edge{
        public:
        int destination;
        int cost;
        Edge(int destination, int cost){
            this -> destination = destination;
            this -> cost = cost;
        }
    };
    
    struct Comparator {
        bool operator()(const Edge& e1, const Edge& e2){
                return e1.cost > e2.cost;
        }
    };
    
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<Edge> graph[n+1];
        for(auto time: times){
            int source = time[0], destination = time[1], cost = time[2];
            graph[source].push_back(Edge(destination, cost));
        }
        
        //print graph
        // cout << "graph: " << endl;
        // for(int i = 1; i < n+1; i++){
        //     cout << i << ": {";
        //     for(Edge edge: graph[i]){
        //         cout << "{" << edge.destination << ", " << edge.cost << "}, ";
        //     }
        //     cout << "}" << endl;
        // }
        
        vector<int> distance(n+1, INT_MAX);
        
        distance[k] = 0;
        priority_queue<Edge, vector<Edge>, Comparator> pq;
        pq.push(Edge(k,0));
        // pq.push(Edge(2,1));
        while(!pq.empty()){
            Edge minEdge = pq.top();
            pq.pop();
            int min_vertex = minEdge.destination, min_cost = minEdge.cost;
            // cout << "minvertex: "<<min_vertex << ", mincost: " << min_cost << endl;
            if(distance[min_vertex] > min_cost)
            distance[min_vertex] = min_cost;
            // else break;
            
            for(auto edge: graph[min_vertex]){
                int vertex = edge.destination, cost = edge.cost;
                // cout << "distance[" << vertex << "] = " << distance[vertex] << endl;
                // cout << "minEdge cost: " << minEdge.cost << "cost: " << cost << endl; 
                if(distance[vertex] > minEdge.cost + cost){
                    distance[vertex] = minEdge.cost + cost;
                    edge.cost = distance[vertex];
                    // cout << distance[vertex] << endl;
                    pq.push(edge);
                }
            }
        }
        
        //distance array:
        // for(auto d: distance) cout << d << ", ";
        // cout << endl;
        
        int maxx = INT_MIN;
        for(int i = 1; i < distance.size(); i++){
            if(distance[i] == INT_MAX) return -1;
            if(maxx < distance[i]) maxx = distance[i];
        }
        // cout << pq.top().cost << endl;
        return maxx;
    }
};