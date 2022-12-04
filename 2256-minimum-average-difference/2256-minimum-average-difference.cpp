class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<long long> prefixsum(n,0);
        
        prefixsum[0] = nums[0];
        
        
        for(int i=1;i<n;i++){
            prefixsum[i] = nums[i] + prefixsum[i-1];
        }
        
        int res = INT_MAX;
        
        int resindex = 0;
        
        int a,b;
        
        for(int i=0;i<n;i++){
            if(i == n-1)
                a = 0;
            else
                a = (prefixsum[n-1]-prefixsum[i])/(n-i-1) ;
            b = (prefixsum[i]/(i+1));
            int diff = a - b;
            
            if(diff < 0) diff *= -1;
            
            if(diff < res){
                resindex = i;
                res = min(res,diff);
            }
        }
        
        return resindex;
    }
};