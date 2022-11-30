class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2100, 0);
        vector<int> vis(1001, -1);
        
        for(int num: arr){
            freq[num + 1000]++;
        }
        
        for(int num: arr){
            
            // This number is evaluated
            if(freq[num + 1000] == -1) continue;
            
            // if the freq is already visited it will not be -1
            if(vis[freq[num + 1000]] != -1) return false;
            
            // cout << vis[freq[num + 1000]] << " ";
            
            vis[freq[num + 1000]] = freq[num + 1000];
            freq[num + 1000] = -1;
        }
        
        return true;
        
    }
};