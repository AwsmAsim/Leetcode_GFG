class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 0;
        for(int i = 0; i < nums.size(); i++){
            cout << candidate << " ";
            if(nums[i] == candidate){
                count++;
            }else{
                count--;
                if(count < 0){
                    candidate = nums[i];
                    count = 0;
                }
            }
        }
        
        return candidate;
    }
};