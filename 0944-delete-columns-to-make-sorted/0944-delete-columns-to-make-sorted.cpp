class Solution {
    
    
    bool isIncreasing(int aIdx, vector<string>& strs, int& n){
        
        for(int i = 1; i < n; i++){
            if(strs[i][aIdx] < strs[i-1][aIdx]) return false;
        }
        
        return true;
    }
    
    bool isDecreasing(int aIdx, vector<string>& strs, int& n){
        
        for(int i = 1; i < n; i++){
            if(strs[i][aIdx] > strs[i-1][aIdx]) return false;
        }
        
        return true;
    }
    
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size(), wordSize = strs[0].size();
        if(n == 1) return 0;
        int counter = 0;
        
        for(int i = 0; i < wordSize; i++){
            if(isIncreasing(i, strs, n)){
                // cout << "Idx: " << i << endl;
                continue;
            } 
            // if(isDecreasing(i, strs, n)) continue;
            ++counter;
            // cout << counter << endl;
        }
        
        return counter;
    }
};