class Solution {
    
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hMap;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            hMap[nums[i]]++;
        } 
        
        for(auto a: hMap){
            if(k > 0 and hMap.find(a.first+k)!=hMap.end() or k==0 and hMap[a.first]>1) ++count;
        }
        
        return count;
    }
};