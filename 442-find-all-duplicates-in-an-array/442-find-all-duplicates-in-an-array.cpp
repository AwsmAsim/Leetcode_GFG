class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0){
                answer.push_back(abs(nums[i]));
            }else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        return answer;
    }
};