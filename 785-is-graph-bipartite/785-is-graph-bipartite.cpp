class Solution {
public:
        bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int, int>> q; //<node, color>
        int n=graph.size();
        vector<int> colors(n, 0);
		//colors: 1, -1, 0(Not colored)
        vector<bool> isVisited(n, false);
        for(int i=0; i<n; i++){
            if(colors[i]) /*means the current node and all the connected nodes 
			to this are bipartite and we dont need to check them. */
                continue;
            q.push({i, 1}); //start BFS from the current node if not colored yet.
            while(!q.empty()){
                auto [node, color] = q.front();
                q.pop();
                if(isVisited[node])
                    continue;
                isVisited[node]=true;
                for(auto child: graph[node]){
                    if(isVisited[child] && colors[child]==color)
                        return false;
                    else if(!isVisited[child]){
                        colors[child]=color*(-1);
                        q.push({child, colors[child]});
                    }
                }   
            }
        }
        return true;
    }
};