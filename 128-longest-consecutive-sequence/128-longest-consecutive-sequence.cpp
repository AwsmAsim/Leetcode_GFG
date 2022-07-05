class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        unordered_map<int, int> hMap, consec;
        int maxC = 1;
        
        for(int i = 0; i < nums.size(); i++) hMap[nums[i]] = i; 
        
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            int element = nums[i];
            while(hMap.find(element)!=hMap.end()){
                ++count;
                element = element + 1;
                if(consec.find(element)!=consec.end()){
                    count += consec[element];
                    break;
                } 
            }
            consec[nums[i]] = count;
            maxC = max(maxC, count);
        }
        
        return maxC;
    }
};