// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
    vector<int> merge(vector<int> arr1, vector<int> arr2){
        
        vector<int> arr3(arr1.size() + arr2.size());
        
        int i = 0, j = 0, k = 0;
        while(i < arr1.size() and j < arr2.size()){
            if(arr1[i] < arr2[j]){
                arr3[k++] = arr1[i++];
            } else {
                arr3[k++] = arr2[j++];
            }
        }
        
        while(i < arr1.size()){
            arr3[k++] = arr1[i++];
        }
        
        while(j < arr2.size()){
            arr3[k++] = arr2[j++];
        }
        
        return arr3;
        
    }
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        
        for(int i = 0; i<arr.size(); i++){
            ans = merge(ans, arr[i]);
        }
        
        return ans;
        
        
        // O(n*m) + O(n log n)
        // vector<int> ans;
        
        // for(int i=0; i < arr.size(); i++){
        //     for(int j = 0; j < arr[i].size(); j++) ans.push_back(arr[i][j]);
        // }
        
        // sort(ans.begin(), ans.end());
        
        // return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends