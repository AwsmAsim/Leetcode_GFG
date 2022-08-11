class Solution {

    int MODi = 1000000007;
    
    long long solve(int num, vector<pair<int, int>> graph[], vector<int>& arr, vector<int>& dp){
        
        // cout << "cal for: "<< arr[num] << endl;
        
        
        if(graph[num].size()==0) return 1;
        if(dp[num]!=-1) return dp[num];
        
        long long count = 0;
        unordered_set<int> set1;
        for(pair<int, int> nbr: graph[num]){
            // if(set1.find(nbr.first)!=set1.end()) continue;
            // set1.insert(nbr.first);
            // set1.insert(nbr.second)
            // cout << nbr.first << endl;
            // if(nbr.first == nbr.second) count += 1+solve(nbr.first, graph, arr);
            // else
            count += ((solve(nbr.first, graph, arr, dp))%MODi * (solve(nbr.second, graph, arr, dp))%MODi)%MODi;
            // if(count == 0) ++count;
            // cout <<'\t' <<  num << ": " << count << endl;
            
        }
        
        dp[num] = (((count)%MODi)+1)%MODi;
        return dp[num];
    }
    
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<pair<int, int>> graph[1001];
        unordered_set<int> set1;
        unordered_map<int, int> indexOf;
        vector<int> dp(arr.size()+1, -1);
        
        for(int i = 0; i < arr.size(); i++){
            indexOf[arr[i]] = i;
            set1.insert(arr[i]);
        }
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(arr[i] == arr[j]) continue;
                bool isDivisible = (arr[i]%arr[j])==0;
                int f2 = arr[i]/arr[j];
                if(isDivisible and set1.find(f2) != set1.end()){
                    // cout << arr[i] << " " << arr[j] << endl;
                    graph[i].push_back({j, indexOf[f2]});      
                }
            }
        }
        
        // Print Graph
        // for(int i = 0; i <= arr.size(); i++){
        //     if(graph[i].size()==0) continue;
        //     cout << arr[i] << ": ";
        //     for(pair<int, int> nbr: graph[i]){
        //             cout << "{" << arr[nbr.first] << "," << arr[nbr.second] << "}, ";
        //     } 
        //     cout << endl;
        // }
        
        long long count = 0;
        for(int i = 0; i < arr.size(); i++){
            int ans = solve(i, graph, arr, dp); 
            // if(ans == 0) ans = 1;
            // ++ans;
            count = ((count)%MODi + (ans)%MODi)%MODi;
            // cout << arr[i] << ": " << ans << endl;
        }
        
        return (int)(count)%MODi;
    }
};