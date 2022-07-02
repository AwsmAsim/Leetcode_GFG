// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    int source = 0, destination = 1;
    
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    
	    int count = 0;
	    vector<int> graph[n];
	    for(int i = 0; i < edges.size(); i++){
	        graph[edges[i][source]].push_back(edges[i][destination]);
	    }
	    

	    stack<int> dfsStack;
	    dfsStack.push(s);
	    
	    while(!dfsStack.empty()){
	        int cNode = dfsStack.top();
	        dfsStack.pop();
	        if(cNode == d){
	            ++count;
	            continue;
	        }
	        for(auto neighbouringNode: graph[cNode]){
	            dfsStack.push(neighbouringNode);
	        }
	    }
	    
	    return count;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends