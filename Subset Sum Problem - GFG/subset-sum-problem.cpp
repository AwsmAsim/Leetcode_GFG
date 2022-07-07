// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{ 
    
    bool recursive(vector<int>& arr, int idx, int sum1, vector<vector<int>>& dp){
        
        // cout << idx << " " << sum1 << endl;
        if(dp[idx][sum1] != -1) return dp[idx][sum1]; 
        if(sum1 == 0) return true;
        if(idx == arr.size()) return false;
        
        int pick, nonPick;
        
        if(arr[idx] <= sum1 and recursive(arr, idx + 1, sum1 - arr[idx], dp)){
            dp[idx][sum1] = true;
        }else if(recursive(arr, idx + 1, sum1, dp))dp[idx][sum1] = true;
        else
        dp[idx][sum1] = false;
        return dp[idx][sum1];
    } 
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        return recursive(arr, 0, sum, dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends