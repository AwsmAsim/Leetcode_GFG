class Solution {
    
    void printList(vector<int> arr){
        for(auto a : arr) cout << a <<",";
        cout << endl;
    }
    
    int bottomUp(vector<int>& cost){
        
        if(cost.size()==2) return min(cost[0], cost[1]);
        
        vector<int> dp(cost.size(), 0);
        dp[0] =  cost[0], dp[1] =  cost[1];
        
        for(int i = 2; i < cost.size(); ++i){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            // printList(dp);
        }
        
        
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return bottomUp(cost);
    }
};