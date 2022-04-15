class Solution {
    
    
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size()-2, last;
        last = nums.size()-1;
        
        for(; i >= 0; i--){
            if(i+nums[i] >= last){
                last = i;
            }
        }
        if(last <= 0) return true;
        return false;
        
    }
};