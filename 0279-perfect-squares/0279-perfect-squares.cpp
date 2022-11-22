class Solution {
public:
    
    vector<int> squares;
    
    int solve(int n, vector<int>& dp){
        
        if( n == 0) return 0;
        if(n < 0) return INT_MAX;
        if(dp[n] != -1) return dp[n];
        
        int minn = INT_MAX;
        
        for(int i = 0; i < squares.size(); i++){
            
            if(squares[i] > n) break;
            int ans = solve(n - squares[i], dp);
            if(ans == INT_MAX) continue;
            minn = min(ans, minn);
            
        }
        
        return dp[n] = ++minn;
        
    }
    
    void _print(vector<int> nums){
        for(int num: nums) cout << num << ", ";
        cout << endl;
    }
    
    int numSquares(int n) {
        
        int sq = 1, num = 1;
        vector<int> dp(10001, -1);
        dp[1] = 1;
        while((num*num) <= n){
            squares.push_back(num*num);
            ++num;
        }
        // _print(squares);
        int ans = solve(n, dp);
        return ans;
    }
};