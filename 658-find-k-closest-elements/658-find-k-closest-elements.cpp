class Solution {
    
    inline int min(const int& a, const int& b){
        if(a < b) return a;
        return b;
    }
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int x_idx;
        
        x_idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        // cout << x_idx << endl;
        if(x_idx >= arr.size()) x_idx = arr.size() - 1;
        if(x_idx > 0 and abs(arr[x_idx-1] - x) <= abs(arr[x_idx] - x)) --x_idx;
        
        
        if(k == 1){
            return vector<int>(1, arr[x_idx]);
        }
        
        int wStart = max(0, x_idx - k + 1);
        int wEnd = min(arr.size()-1, x_idx + k - 1);
        
        // cout << "wStart: " << wStart << " wEnd: " << wEnd << endl;
        
        while(wEnd - wStart + 1 > k){
            if(abs(arr[wStart] - x) <= abs(arr[wEnd] - x)){
                --wEnd;
            }else ++wStart;
        }
        
        vector<int> ans;
        for(; wStart <= wEnd; ++wStart){
            ans.push_back(arr[wStart]);
        }
        
        return ans;
        
    }
};