class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            // cout << i << ": " << nums[i] << endl;
            if(i + nums[i] >= nums.size()-1) return ++count;
            int maxElement = INT_MIN, newIdx = i;
            for(int j = 1; j <= nums[i]; j++){
                // cout << nums[i+j] << " " << maxElement << " j: " << j << endl;
                if(nums[i+j]+j >= maxElement){
                    maxElement = nums[i+j] + j;
                    newIdx=i+j;
                } 
            }
            i = newIdx;
            // cout<< "updated i:" << i <<endl;
            --i;
            ++count;
        }
        return 0;
    }
};