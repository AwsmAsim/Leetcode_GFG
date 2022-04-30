class Solution {
public:
    vector<double> res;
    unordered_map<string,list<pair<string,double>>> h;
    
    void addedge(string u, string v,double x)
    {
        h[u].push_back(make_pair(v,x));
        h[v].push_back(make_pair(u,1/x));
    }
    
    double sssp(string src,string dest)
    {
        if(h.find(src)==h.end() || h.find(dest)==h.end())
        {
            return -1.0;
        }
        queue<string>q;
        q.push(src);
        unordered_map<string,bool>visited;
        unordered_map<string,double>dist;
        visited[src] = true;
        dist[src] = 1;
        while(!q.empty())
        {
            string node = q.front();
            q.pop();
            for(auto children : h[node])
            {
                if(visited[children.first]==false)
                {
                    q.push(children.first);
                    visited[children.first] = true;
                    dist[children.first] = dist[node]*(children.second);
                }
            }
        }
        double d = dist[dest];
        if(d==0)
        {
            d = -1;
        }
        return d;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     
        for(int i=0;i<values.size();i++)
        {
            addedge(equations[i][0],equations[i][1],values[i]);
        }
        int n = queries.size();
        for(int i=0;i<n;i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];
            double p = sssp(src,dest);
            res.push_back(p);
        }
        return res;
    }
};