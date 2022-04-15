class Solution {
    
    void print1d(vector<int> arr){
        cout << endl;
        for(auto a: arr) cout << a << ", ";
        cout << endl;
    }
    
    void printMap(unordered_map<int, int> hMap){
        cout << endl;
        for(auto a: hMap) cout << a.first << ": " << a.second << ",  ";
        cout << endl;
    }
    
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        vector<int> prefSum(n,0);
        prefSum[0]=nums[0];
        unordered_map<int, int> hMap;
        
        for(int i = 1; i < nums.size(); i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        // print1d(prefSum);
        for(int i = 0; i < nums.size(); i++){
            prefSum[i] = (prefSum[i]%k);
            if(prefSum[i]<0)
                prefSum[i] = (k + (prefSum[i]%k));
        }
        // print1d(prefSum);
        
        for(int i = 0; i < prefSum.size(); i++){
            hMap[prefSum[i]]++;
        }
        // printMap(hMap);
        hMap[0]++;
        count = 0;
        for(auto a: hMap){
            // if(a.first == 0) count += 1;
            int b = a.second - 1;
            count += b*(b + 1)/2;
        }
        
        
        
        return count;
    }
};