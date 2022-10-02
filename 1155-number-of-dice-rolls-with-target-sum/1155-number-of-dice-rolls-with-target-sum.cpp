class Solution {
    
    int MOD = (int)1000000007;
    
    int solveMemo(int target, int noOfDice, int& point, vector<vector<int>>& dp){
        
        // cout << target << " " << noOfDice << " " << point << endl;
        if(noOfDice == 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[target][noOfDice] != -1){
            return dp[target][noOfDice];
        }
        
        int totalPoint = (int)((long long)(noOfDice * point));
        int totalWays = 0;
        
        for(int i = 1; i <= min(target-(noOfDice-1), point); i++){
            int noOfWays = solveMemo(target - i, noOfDice - 1, point, dp);
            totalWays += (noOfWays)%MOD;
            totalWays %= MOD;
        }
        
        return dp[target][noOfDice] = ((int)totalWays);
    }
    
    
    // noOfDice --> n
    // point --> k
    int solveRec(int target, int noOfDice, int& point){
        
        if(noOfDice == 0){
            if(target == 0) return 1;
            return 0;
        }
        
        int totalPoint = (int)((long long)(noOfDice * point));
        int totalWays = 0;
        
        for(int i = 1; i <= min(target-(noOfDice-1), point); i++){
            int noOfWays = solveRec(target - i, noOfDice - 1, point);
            totalWays = (int)((long long) (totalWays + noOfWays));
        }
        
        return ((int)totalWays);
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        if(target < n) return 0;
        
        vector< vector<int> > dp(target+1, vector<int>(n + 1, -1));
        return solveMemo(target, n, k, dp);
        
        return solveRec(target, n, k);
    }
};