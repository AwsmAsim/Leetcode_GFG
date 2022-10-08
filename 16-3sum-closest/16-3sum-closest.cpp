class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, minDiff = INT_MAX;
        
        int startPtr = 0, endPtr = nums.size()-1, start, end = nums.size()-1;
        
        for(int i = 0; i < nums.size()-2; i++){
            start = i+1, end = nums.size()-1;
            while(start < end){
                int newSum = nums[i] + nums[start] + nums[end];
                if(abs(target - newSum) < minDiff){
                    minDiff = abs(target - newSum);
                    ans = newSum;
                }
                
                if(ans == target) return target;
                else if(newSum < ans) ++start;
                else --end;
            }
            
        }
        
        
        return ans;
        
    }
};