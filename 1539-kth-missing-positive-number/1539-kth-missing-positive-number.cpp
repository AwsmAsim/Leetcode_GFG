class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1, mid;
        int missing;
        
        while(start <= end){
            
            // cout << "start: " << start << " end: " << end << " mid: " << mid << endl;
                
            mid = (start + end)/2;
            
            missing = arr[mid] - (mid+1);
            // cout << "missing: " << missing << endl;
            
            if(missing < k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        

        
        if(missing < k){
            missing = k - (arr[mid] - (mid+1));
            return arr[mid] + missing;
        }
        
        if(mid == 0){
            return k;
        }
        missing = k - (arr[mid-1] - mid);
        return arr[mid - 1] + missing;
        
        
        
    }
};