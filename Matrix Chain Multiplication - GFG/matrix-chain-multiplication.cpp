// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int solve(int arr[], int i, int j, vector<vector<int>>& dp){
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i >= j){
            return 0;
        }
        
        int mn = INT_MAX;
        
        for(int k = i; k < j; k++){
            int temp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1] * arr[k] * arr[j];
            if(temp < mn) mn = temp;
        }
        dp[i][j] = mn;
        return dp[i][j];
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return solve(arr, 1, N-1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends