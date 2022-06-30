class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2], steps = 0;
        
        for(int i = 0; i < nums.size(); i++){
            steps += abs(nums[i]-median);
        }
        
        return steps;
    }
};