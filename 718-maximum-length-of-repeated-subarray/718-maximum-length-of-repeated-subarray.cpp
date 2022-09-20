class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int maxVal = INT_MIN;
        
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        
        return maxVal;
        
        
    }
};