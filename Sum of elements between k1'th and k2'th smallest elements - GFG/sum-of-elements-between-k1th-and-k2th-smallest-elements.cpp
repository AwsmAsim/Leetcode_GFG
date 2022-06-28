// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        // int n = sizeof(A)/sizeof(A[0]);
        // cout << "size: " << n << endl;
        sort(A, A+N);
        long long answer1 = 0;
        
        // for(int i = 0; i < n; i++) cout << A[i] << " " << endl;
        
        for(int i = K1; i < K2-1; i++) answer1 += A[i];
        
        return answer1;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends