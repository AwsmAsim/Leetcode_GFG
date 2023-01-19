class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size(), count = 0;
        vector<int> preSum(n, 0);
        unordered_map<int, int> arrived;
        arrived[0] = 1;
        
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            preSum[i] += preSum[i-1] + nums[i];
        }
        
        for(int i = 0; i < n; i++){
            
            int modValRequired = preSum[i]%k;
            // cout << modValRequired << endl;
            if(modValRequired < 0) modValRequired += k;
            
            if(arrived.find(modValRequired) != arrived.end()) count += arrived[modValRequired];
            
            ++arrived[modValRequired]; 
            
        }
        
        return count;
        
    }
};