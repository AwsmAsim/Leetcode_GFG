class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int ptr1 = 0, ptr2 = 0;
        int dup, missing;
        
        for(int i = 0; i < nums.size(); i++){
            // cout << i << endl;
            while(nums[i] != (i+1)){
                // cout << "\t" << i << endl;
                if(nums[nums[i]-1] == nums[i]){
                    dup = nums[i];
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i = nums.size()-1; i>=0; i--){
            while(nums[i] != (i+1)){
                // cout << "\t" << i << endl;
                if(nums[nums[i]-1] == nums[i]) {
                    missing = (i+1);
                    break;
                };
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        // for(int num: nums){
        //     cout << num << ", ";
        // }
        // cout << endl;
        
        
        return {dup, missing};
    }
};