class Solution {
    
    void printList(vector<int> v){
        for(auto a: v){
            cout << a << "  ";
        }
        cout << endl;
    }
    
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        queue<int> q;
        vector<int> colors(graph.size(), -1);
        vector<int> visited(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); i++){
            if(colors[i] == -1){
                q.push(i);
                colors[i] = 1;
                int parentColor = 1;
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    for(auto node: graph[top]){
                        if(colors[node]==-1){
                            // cout << node << " ." << top << endl;
                            // printList(colors);
                            q.push(node);
                            colors[node] = 1 - colors[top];
                        }else{
                            // cout << node << " " << top << endl;
                            // printList(colors);
                            if(colors[node] == colors[top]) return false;
                            
                        }
                    }
                }
            }
        }
        
        return true;
    }
};