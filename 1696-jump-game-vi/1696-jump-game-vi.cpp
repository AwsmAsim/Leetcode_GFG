class Solution {

    
    int recursive(int idx, int& k, vector<int>& nums){
        if(idx == nums.size()-1) return nums[nums.size()-1];
        if(idx > nums.size()) return INT_MIN;
        
        
        int minn = INT_MIN;
        for(int i = 1; i <= k; i++){
            int recAns = recursive(idx + i, k, nums); 
            if(recAns == INT_MIN) continue;
            int ans = nums[idx] + recAns;
            minn = max(minn, ans);
        }
        
        return minn;
        
    }
    
    int tabulation(int& k, vector<int>& nums){
        priority_queue<pair<int, int>> maxHeap;
        // int prevMax = INT_MIN;
        vector<int> dp(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++){
            
            pair<int, int> cMax;
            int idx, val;
            if(!maxHeap.empty()){
                cMax = maxHeap.top();
                idx = cMax.second, val = cMax.first;
            }else{
                val = 0;
            }
            
            while(maxHeap.size() > k and idx < (i - k)){
                maxHeap.pop();
                cMax = maxHeap.top();
                idx = cMax.second, val  = cMax.first;
                // cout << idx << " " << endl;
            }
            
            // cout << "val: " << val << endl;
            dp[i] = nums[i] + val;
            maxHeap.push({dp[i], i});
            
        }
        
        return dp[dp.size()-1];
    }
    
    
public:
    int maxResult(vector<int>& nums, int k) {
        return tabulation(k, nums);
        return recursive(0, k, nums);
    }
};