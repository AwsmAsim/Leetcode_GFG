class Solution {
    
    
    bool recursive(int idx, vector<int>& arr){
        
        if(idx < 0 or idx >= arr.size()) return false;
        if(arr[idx] == 0) return true;
        if(arr[idx] < 0) return false;
        arr[idx] = -1 * arr[idx]; 
        
        if(recursive(idx + arr[idx], arr)){
            return true;
        }else if(recursive(idx - arr[idx], arr)){
            return true;
        }
        
        return false;
    }
    
    
public:
    bool canReach(vector<int>& arr, int start) {
        return recursive(start, arr);
    }
};