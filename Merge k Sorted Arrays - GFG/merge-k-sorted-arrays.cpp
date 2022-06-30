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
    
    
    
struct comparator{
        bool operator()(const pair<int,int> v1, const pair<int,int> v2){
            return v1.first > v2.first;
        }
    };
    

vector<int> sortWithHeap(vector<vector<int>> arr, int K){
    // cout<<"1"<<" ";
    
    vector<int> ans;
    
    vector<int> itrs(arr.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq, pq2; // {value, outer array index}
    
    for(int i = 0; i < arr.size(); i++){
        pq.push({arr[i][0], i});
    }
    while(!pq.empty()){
        // cout << 1 << " ";
        pair<int, int> topPair = pq.top();
        pq.pop();
        itrs[topPair.second]++;
        
        if(itrs[topPair.second] < arr[topPair.second].size())
            pq.push({arr[topPair.second][itrs[topPair.second]], topPair.second});
        ans.push_back(topPair.first);
        
        
        // print pq
        // pq2 = pq;
        // while(pq2)
    }
    
    return ans;
    
}
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        return sortWithHeap(arr, K);
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