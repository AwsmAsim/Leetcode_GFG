class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], vote = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==candidate) ++vote;
            else if(vote > 0){
                --vote;
                if(vote == 0)
                {
                    candidate = nums[i];
                    ++vote;
                }
            }else candidate =nums[i];
            
        }
        
        return candidate;
    }
};