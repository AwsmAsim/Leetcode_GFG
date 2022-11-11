class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, curr_element;
        for(int i = 0; i < nums.size(); i++){
            curr_element = nums[i];
            ++i;
            while(i<nums.size() and nums[i]==curr_element){
                nums[i] = 101;
                i++;
            }
            --i;
            ++count;
        }
        sort(nums.begin(), nums.end());
        return count;
    }
};