#User function Template for python3

from heapq import *

class Solution:
    def kthSmallest(self,arr, l, r, k):
        '''
        arr : given array
        l : starting index of the array i.e 0
        r : ending index of the array i.e size-1
        k : find kth smallest element and return using this function
        '''
        
        top = 0
        
        pq = []
        
        for i in range(0, k):
            heappush(pq, -arr[i])
            
        for i in range(k, r + 1):
            if -pq[top] >= arr[i]:
                heappop(pq)
                heappush(pq, -arr[i])
                
        # print(pq)
        return -pq[0]
        
        # arr.sort()
        # return arr[k-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    import random 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=list(map(int,input().strip().split()))
        k=int(input())
        ob=Solution()
        print(ob.kthSmallest(arr, 0, n-1, k))
        
# } Driver Code Ends