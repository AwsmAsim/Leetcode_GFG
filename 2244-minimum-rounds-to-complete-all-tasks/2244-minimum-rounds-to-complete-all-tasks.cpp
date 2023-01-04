class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hMap;
        int count = 0;
        
        for(int i = 0; i < tasks.size(); i++){
            ++hMap[tasks[i]];
        }
        
        for(pair<int, int> p: hMap){
            pq.push(pair<int, int>(p.second, p.first));
        }
        
        while(!pq.empty()){
            ++count;
            int count = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            
            if(count == 1) return -1;
            
            // cout << "do for " << val << endl;
            
            if(count == 2 or count == 3) continue;
            if(count == 4){
                pq.push(pair<int, int>(2, val));
            }else{
                pq.push(pair<int, int>(count - 3, val));
            }
        }
        
        return count;
        
    }
};