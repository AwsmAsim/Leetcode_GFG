//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int solveRec(int idx, int n, vector<int>& prices, vector< vector<int> >& dp){

        if(n==0) return 0;
        if(idx < 0) return 0;
        if(dp[n][idx] != -1) return dp[n][idx];
        
        int pick = 0;
        if(idx < n)
        pick = prices[idx] + solveRec(idx, n-(idx+1), prices, dp);
        int notPick = solveRec(idx - 1, n, prices, dp);
        
        
        return dp[n][idx] = max(pick, notPick);
    }
    
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> prices;
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i < n; i++){
            prices.push_back(price[i]);
        }
        return solveRec(n-1, n, prices, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends