class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, temp;
        for(i = 0; i < nums.size(); i++){
            if(nums[i]==0) break;
        }
        j = i + 1;
        for(; j < nums.size(); j++){
            if(nums[j] != 0){
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
                // j++;
            }
        }
    }
};