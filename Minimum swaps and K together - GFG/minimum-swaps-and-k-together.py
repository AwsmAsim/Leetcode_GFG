#User function Template for python3

def minSwap (arr, n, k) : 
    #Complete the function
    wSize = 0
    for i in arr:
        if i <= k:
            wSize += 1
            
    count = 0
    maxCount = 0
    for i in range(0, wSize):
        if arr[i] > k:
            count +=1
            
    maxCount = max(maxCount, count)

    # print(count, wStart, wEnd, end = " ")
    wStart = 0
    
    for wEnd in range(wSize, len(arr)):
        # print(arr[wEnd], arr[wStart], end="  ")
        if(arr[wStart] > k):
            count -= 1
        if(arr[wEnd] > k):
            count += 1
            
        maxCount = min(maxCount, count)
        wStart += 1
        # print(count, end = ", ")
        
    return maxCount
            
        
        
    
    
    




#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    k = int(input())
    ans = minSwap(arr, n, k)
    print(ans)
    





# } Driver Code Ends