class Solution {
    
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set1;
        int pos = 1;
        for(auto a: nums){
            if(a==pos){
                ++pos;
                while(set1.find(pos)!=set1.end()) ++pos;
            }
            set1.insert(a);
        }
        
        return pos;
    }
};