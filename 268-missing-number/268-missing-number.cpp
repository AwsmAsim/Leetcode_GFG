class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ptr, curNum;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i]!=i){
                curNum = nums[i];
                if(curNum == nums.size()) break;
                swap(nums[curNum], nums[i]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i) return i;
        }
        
        return nums.size();
    }
};