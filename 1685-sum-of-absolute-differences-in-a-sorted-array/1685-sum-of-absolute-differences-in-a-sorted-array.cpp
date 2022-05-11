class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, lSum = 0;
        
        vector<int> prefSum(n, 0), answer(n,0);
        prefSum[0] = nums[0];
        for(int i = 0; i < nums.size(); i++) sum1 += nums[i];
        // cout << sum1<< endl;
        
        for(int i = 0; i < nums.size(); i++){
            int rightSum, leftSum;
            // cout << "for " << i << ":" << endl;
            if(i == 0) leftSum = 0;
            else leftSum = lSum - (nums[i]*(i));
            // cout << "leftSim: " << leftSum  << ", ";
            
            if(i==nums.size()-1) rightSum = 0;
            
            // prefSum[i] = lSum + nums[i], prefSum[nums.size()-1] = sum1
            else rightSum = sum1 - (lSum + nums[i]) - (nums[i]*(n-i-1));
            // cout << "rightSum: " << rightSum << endl;
            
            answer[i] = abs(rightSum) + abs(leftSum);
            lSum += nums[i];
        }
        
        return answer;
        
    }
};