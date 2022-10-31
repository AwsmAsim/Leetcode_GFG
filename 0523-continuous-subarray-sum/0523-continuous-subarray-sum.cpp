class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return false;
        
        // 23, 2, 4, 7, 7
        int n = nums.size();
        unordered_map<int, int> occured;
        occured.insert({0, -1});
        
        for(int i = 0; i < n; i++){
            if(i != 0) nums[i] += nums[i-1];
            if(i==0){
                // if(nums[i] != 0 and nums[i]%k == 0) return true;
                nums[i] %= k;
                
            }else{
                nums[i] %= k;
                if(occured.find(nums[i]) != occured.end() and occured[nums[i]] != i-1) return true;
            }
            if(occured.find(nums[i]) == occured.end())
            occured[nums[i]] = i;
        }
        
        // cout << "Resultant array: " << endl;
        // for(int num: nums) cout << num << ", ";
        // cout << endl;
        
        return false;
    }
};