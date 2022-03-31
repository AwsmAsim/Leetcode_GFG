class Solution {

    int mcm(vector<int>& nums, int m, int i, int j, int pNo){
        int l = INT_MIN, r = 0, mid=0, ans=0;
        for(int i = 0; i < nums.size(); i++) l = max(l, nums[i]);
        for(int i = 0; i < nums.size(); i++) r += nums[i];
        while(l<=r){
            mid = l + (r-l)/2;
            int tempSum = 0, count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(tempSum+nums[i] <= mid)
                tempSum += nums[i];
                else{
                    ++count;
                    tempSum = nums[i];
                }
            }
            ++count;
            if(count<=m){
                r= mid-1;
                ans = mid;
            }else l = mid + 1;
            
        }
        return ans;
    }
    
    
public:
    int splitArray(vector<int>& nums, int m) {
        return mcm(nums, m, 0, nums.size()-1, 1);
        
    }
};