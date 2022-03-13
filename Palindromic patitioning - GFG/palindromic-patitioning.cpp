// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    // bool isPalindrome(int i, int j, string str){
        
    //     for(int k = 0; k < (j-i)/2; k++){
    //         if(str[i+k]!=str[j-k]) return false;
    //     }
        
    //     return true;
    // }
    bool isPalindrome(string& String, int i, int j)
    {
        while(i < j)
        {
          if(String[i] != String[j])
            return false; 
          i++;
          j--;
        }
        return true;
    }
    
    int mcm(int i, int j, string& str, vector<vector<int>>& dp){
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i>=j){
            return 0;
        }
        
        if(isPalindrome(str, i, j)){
            // cout << " Palindrome at: " << i << " " << j << endl;
            return 0;
        }
        
        int minC = INT_MAX, count;
        
        for(int k = i; k < j; k++){
            count = 1 + mcm(i, k, str, dp) + mcm(k+1, j, str, dp);
            // if(count == 1) cout << "i:" << i << " j:" << j << " ";
            minC = min(minC, count);
        }
        
        dp[i][j] = minC;
        
        return dp[i][j];
    }
    
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return mcm(0, str.size()-1, str, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends