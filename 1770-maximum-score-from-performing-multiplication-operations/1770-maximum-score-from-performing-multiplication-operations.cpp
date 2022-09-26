class Solution {
    
    
    int memo(int idx, int start, vector<int>& arr, vector<int>& mul, vector<vector<int>>& dp){
        
        if(idx == mul.size()) return 0;
        int endUsed = (idx) - start; 
        int end = arr.size() - 1 - endUsed;
        
        if(start > end) return 0; 
        
        // cout << start << " " << end << endl;
        
        if(dp[idx][start] != -1) return dp[idx][start];
        
        int pickStart = (mul[idx] * arr[start]) + memo(idx + 1, start + 1, arr, mul, dp);
        int pickEnd = (mul[idx] * arr[end]) + memo(idx + 1, start, arr, mul, dp);
        
        return dp[idx][start] = max((int)pickStart, (int)pickEnd);
        
    }
    
    int recur(int idx, int start, int end, vector<int>& arr, vector<int>& mul){
        
        if(idx == mul.size()) return 0;
        if(start > end) return 0; 
        
        int pickStart = (mul[idx] * arr[start]) + recur(idx + 1, start + 1, end, arr, mul);
        int pickEnd = (mul[idx] * arr[end]) + recur(idx + 1, start, end - 1, arr, mul);
        
        return max((int)pickStart, (int)pickEnd);
        
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size()+1, vector<int>(nums.size()+1, -1));
        return memo(0, 0, nums, multipliers, dp);
        return recur(0, 0, nums.size()-1, nums, multipliers);
    }
};