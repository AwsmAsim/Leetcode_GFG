class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());
        dp[0] = arr[0];
        int lastSum = 0;
        
        for(int i = 1; i < arr.size(); i++){
            int mx = INT_MIN, maxS = INT_MIN;
            for(int j = i; j >= max(0, i - k+ 1); j--){
                mx = max(arr[j], mx);
                
                if(j>0) maxS = max(maxS, dp[j-1] + mx*(i-j+1));
                else maxS = max(maxS, mx*(i-j+1));
            }
            dp[i] = maxS;
        }
        
        return dp[arr.size()-1];
    }
};