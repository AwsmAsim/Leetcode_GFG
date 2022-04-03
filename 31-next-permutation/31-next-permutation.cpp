class Solution {
    
public:
    void nextPermutation(vector<int>& nums) {
        int threshold = -1, localMaxima;
        for(int i = nums.size()-1; i > 0 ; i--){
            if(nums[i] > nums[i-1]){
                threshold = i-1;
                break;
            } 
        }
        if(threshold == -1) reverse(nums.begin(), nums.end());
        else{
            for(int i = nums.size()-1; i>=0; i--){
                if(nums[i] > nums[threshold]){
                    // cout << "nums[" << i << "]" << ">" << nums[threshold] << endl;
                    swap(nums[i], nums[threshold]);
                    break;
                }
            }
            if(threshold < nums.size()-1)
            reverse(nums.begin() + threshold + 1, nums.end());
        }
    }
};