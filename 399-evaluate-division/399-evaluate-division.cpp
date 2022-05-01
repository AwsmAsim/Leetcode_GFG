class Solution {
    
//     double dfs(vector<pair<int, double>> graph[], int N, int initial, int destination){
//         stack<int> s1;
//         // int N = graph->size();
//         // cout << "N: " << N << endl;
//         vector<int> visited(N, -1);
//         double product = (double)1;
//         bool startCalculating  = false;
        
//         for(int i = 0; i < N; i++){
//             if(visited[i]==-1){
//                 s1.push(i);
//                 // visited[i] == 1;
//                 while(!s1.empty()){
//                     // cout << "stack size: " << s1.size() << endl;
//                     int top = s1.top();
//                     s1.pop();
//                     visited[top] = 1;
//                     if(top == initial) startCalculating = true;
//                     // cout << "top: " << top << endl;
//                     for(auto edge: graph[top]){
//                         if(startCalculating) product *= edge.second;
//                         // cout << "\nproduct: " << product;
//                         if(edge.first == destination) return (double)product;
//                         if(visited[edge.first] == -1) s1.push(edge.first);
//                     }
//                 }
//             }
//         }
        
//         return (double)-2;
        
//     }
    
    double dfs1(vector<pair<int, double>> graph[], int N, int initial, int destination){
        stack<int> s1;
        // int N = graph->size();
        // cout << "N: " << N << endl;
        vector<int> visited(N, -1);
        // double product = (double)1;
        bool startCalculating  = true;
        unordered_map<int, double> products;
        products[initial] = 1;

        visited[initial] = 1;
        s1.push(initial);
        while(!s1.empty()){
            // cout << "stack size: " << s1.size() << endl;
            int top = s1.top();
            s1.pop();
            visited[top] = 1;
            // if(top == initial) startCalculating = true;
            // cout << "top: " << top << endl;
            for(auto edge: graph[top]){
                if(visited[edge.first]==-1) products[edge.first] = products[top]*edge.second;
                // cout << "\nproduct: " << product;
                if(edge.first == destination) return products[destination];
                if(visited[edge.first] == -1) s1.push(edge.first);
            }
        }
    

        return (double)-2;
        
    }
    
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, int> vertex;
        int sVertex = 0;
        
        
        for(int i = 0; i < equations.size(); i++){
            string initial = equations[i][0];
            string destination = equations[i][1];
            // double weight = values[i];
            
            if(vertex.find(initial) == vertex.end()){ // initial node is not mapped 
                vertex[initial] = sVertex;
                ++sVertex;
            }
            
            if(vertex.find(destination) == vertex.end()){ // final node is not mapped 
                vertex[destination] = sVertex;
                ++sVertex;
            }
            
        }
        
        // cout << "Mapped vertex: ";
        // for(auto a: vertex){
        //     cout << a.first << ":" << a.second <<"   ";
        // }
        // cout << endl;
        
        int N = vertex.size();
        vector<pair<int, double>> graph[N]; // vertex number: weight
        
        for(int i = 0; i < equations.size(); i++){
            string initial = equations[i][0];
            string destination = equations[i][1];
            double weight = values[i];
            
            graph[vertex[initial]].push_back({vertex[destination], weight});
            graph[vertex[destination]].push_back({vertex[initial], 1/weight});
        }
        
        
        // cout << "Graph: ";
        // for(int i = 0; i < N; i++){
        //     cout << i << ": [ ";
        //     for(auto a: graph[i]){
        //         cout << "(" << a.first << ", " << a.second << "), " ;
        //     }
        //     cout << "],\t";
        // }
        
        vector<double> answers;
        // cout << "\nanswer: " << answer << endl;
        // double answer1 = dfs1(graph, N, 0, 2);
        // cout << "\nanswer1: " << answer1 << endl;
        
        for(int i = 0; i < queries.size(); i++){
            
            // If any invalid vertex, return -1
            if(vertex.find(queries[i][0])==vertex.end() or vertex.find(queries[i][1])==vertex.end()){
                answers.push_back((double)-1);
            }
            else if(queries[i][0] == queries[i][1]) answers.push_back((double)1);
            else{
                
                // Vertex are valid.
                double answer1 = dfs1(graph, N, vertex[queries[i][0]], vertex[queries[i][1]]);
                // cout << "for: " << queries[i][0] << " and " << queries[i][1] << " -> " << answer1 << endl;
                
                if(answer1 < -1){
                    // Direct is not present
                    // answer1 = dfs1(graph, N, vertex[queries[i][1]], vertex[queries[i][0]]);
                    // // Evem the reciprocal is not present
                    // if(answer1<-1){
                        // Add -1.000000
                        answers.push_back((double)-1);
                    // }else answers.push_back((double)1/ answer1); // Reciprocal present
                }else 
                    answers.push_back(answer1);
            }
        }
        // Check if the variables are in the graph
        // If the variables are connected
        
        // DFS on the numerator and multply all values 
        // untill it reaches the numerator
        
        // If not, then check from the numerator
        
        return answers;
    }
};