class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0, target;
        for(auto a: nums){
            total += a;
        }
        
        target = total - x;
        
        // cout << "target: " << target << endl;
        if(target == 0) return nums.size();
        
        int wEnd = 0, wStart = 0, wSize = 1, wSum = 0, maxSize = -1;
        for(;wEnd < nums.size(); ++wEnd){
            
            wSum += nums[wEnd];
            
            while(wSum > target and wStart < wEnd){
                
                wSum -= nums[wStart];
                ++wStart;
            }
            
            wSize = wEnd - wStart + 1;
            
            if(wSum == target) maxSize = max(maxSize, wSize);
            // cout << "wSum: " << wSum << " wSize: " <<wSize << " maxSize: " << maxSize << endl; 
        }
        
        if(maxSize == -1) return maxSize;
        return (nums.size() - maxSize);
    }
};