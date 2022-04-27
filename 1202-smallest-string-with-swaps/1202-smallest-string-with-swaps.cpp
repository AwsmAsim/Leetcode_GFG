class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> graph[s.size()];
        int u, v, N = s.size();
        for(auto edge: pairs){
            u = edge[0];
            v = edge[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        
        // Print Graph
        // for(int i = 0; i < N; i++){
        //     cout << i << ":";
        //     for(auto a: graph[i]) cout << a << ", ";
        //     cout << endl;
        // }
        
        vector<int> visited(N+1, 0);
        vector<vector<int>> connectedComponents;
        
        queue<int> q;
        
        for(int i = 0; i < N; i++){
            if(visited[i]==0){
                vector<int> v;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    v.push_back(top);
                    // cout << "In " << i << endl;
                    for(auto a: graph[top]){
                        // cout << "\ttraversed: " << a << endl;
                        if(visited[a] == 0){
                            visited[a] = 1;
                            q.push(a);
                        }
                    }
                }
                sort(v.begin(), v.end());
                connectedComponents.push_back(v);
            }
        }
        
        vector<vector<char>> sorteds;
        
        // Print Component
        // for(auto component: connectedComponents){
        //     cout << "{";
        //     for(auto a: component) cout << a << ", ";
        //     cout << "}" <<endl; ;
        // }
        
        for(auto component: connectedComponents){
            vector<char> v;
            for(auto a: component) v.push_back(s[a]);
            sort(v.begin(), v.end());
            sorteds.push_back(v);
        }
        
        for(int i = 0; i < connectedComponents.size(); i++){
            for(int j = 0; j < connectedComponents[i].size(); j++){
                s[connectedComponents[i][j]] = sorteds[i][j];
            }
        }
        
        
        
        return s;
        
    }
};