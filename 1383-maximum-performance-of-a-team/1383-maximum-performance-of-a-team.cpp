class Solution {
    
    int solve(int n, vector<int>& speed, vector<int>& efficiency, int k){
        vector<pair<int,int>> EffSpeed;
        for(int i = 0; i < speed.size(); ++i){
            EffSpeed.push_back(pair<int, int>(efficiency[i], speed[i]));
        }
        
        sort(EffSpeed.rbegin(), EffSpeed.rend()); // decreasing order
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        long long sSum = 0, ans = INT_MIN;
        for(int i = 0; i < EffSpeed.size(); i++){
            sSum += EffSpeed[i].second;
            pq.push(EffSpeed[i].second);
            if(pq.size() > k){
                sSum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sSum * EffSpeed[i].first);
        }
        
        return ans%((int)(1e9+7));
    }
    
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        return solve(n, speed, efficiency, k);
    }
};