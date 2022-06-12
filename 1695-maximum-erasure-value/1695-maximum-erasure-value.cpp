class Solution {
    
    void printSet(unordered_set<char> set1){
        for(auto a: set1){
            cout << a << ", ";
        }
        cout << endl;
    }
    
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // if(nums.size()==0) return 0;
        // if(s.size()==1) return 1;
        
        int wStart = 0, wEnd = 0, wSize = wEnd - wStart + 1, maxSum = 0, wSum = 0;
        unordered_set<int> cDuplicates;
        
        while(wEnd < nums.size()){
            
            while(cDuplicates.find(nums[wEnd]) != cDuplicates.end()){
                wSum  -= nums[wStart];
                cDuplicates.erase(nums[wStart]);
                ++wStart;
            }
            
            cDuplicates.insert(nums[wEnd]);
            // printSet(cDuplicates);
            
            wSum += nums[wEnd]; 
            // wSize = cDuplicates.size();
            // cout << wSize << endl;
            
            maxSum = max(maxSum, wSum);
            
            // cout << "maxSize: " << maxSize << endl;
            
            ++wEnd;
        }
        
        return maxSum;
    }
};