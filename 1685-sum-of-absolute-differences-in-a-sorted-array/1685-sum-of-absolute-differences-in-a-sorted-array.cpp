class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        
        vector<int> prefSum(n, 0), answer(n,0);
        prefSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            int rightSum, leftSum;
            // cout << "for " << i << ":" << endl;
            if(i == 0) leftSum = 0;
            else leftSum = prefSum[i-1] - (nums[i]*(i));
            // cout << "rightSum: " << leftSum  << ", ";
            
            if(i==nums.size()-1) rightSum = 0;
            else rightSum = prefSum[nums.size()-1] - prefSum[i] - (nums[i]*(n-i-1));
            // cout << "leftSum: " << leftSum << endl;
            
            answer[i] = abs(rightSum) + abs(leftSum);
        }
        
        return answer;
        
    }
};