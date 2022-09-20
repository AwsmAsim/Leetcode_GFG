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
    
    
    bool bfs(int start, vector<int>& arr){
        queue<int> Q;
        Q.push(start);
        
        while(!Q.empty()){
            int top = Q.front();
            Q.pop();
            
            if(top < 0 or top > arr.size()-1 or arr[top] < 0) continue;
            if(arr[top] == 0) return true;
            
            Q.push(arr[top] + top);
            Q.push(top - arr[top] );
            
            arr[top] *= -1;
        }
        
        return false;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        return bfs(start, arr);
        return recursive(start, arr);
    }
};