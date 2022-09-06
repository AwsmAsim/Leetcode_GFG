class Solution {
    
    void _print(vector<int> nums){
        for(int num: nums) cout << num << ",";
        cout << endl;
    }
    
    int recursive(vector<int>& nums, int idx)
    {
        if(idx >= nums.size()) return 0;
        int pick = nums[idx] + recursive(nums, idx + 2);
        int nonPick = recursive(nums, idx + 1);
        
        return max(pick, nonPick);
    }
    
    int tab1(vector<int>& nums){
        // cout << 1 << endl;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);

        // cout << 2 << endl;
        vector<int> dp(nums.size()+1, 0);
        // cout << 3 << endl;
        dp[1]=nums[0], dp[2] = max(nums[0], nums[1]);
        

        for(int i = 2; i <= nums.size(); i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }

        // for(int a: dp) cout << a << ", ";
        // cout << endl;
        // return 0;
        return dp[dp.size()-1];
    }
    
    int tabulation(vector<int>& nums){
        
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        
        return dp[nums.size()-1];
    }
    
    int solve(vector<int>& arr){

        if(arr.size() == 1) return arr[0];
        if(arr.size() == 2) return max(arr[0], arr[1]);

        arr[1] = max(arr[0], arr[1]);
        for(int i = 2; i < arr.size(); i++){
            arr[i] = max(arr[i-1], arr[i] + arr[i-2]);
        }
        return arr[arr.size()-1];
    }
    
    int solveIncExc(vector<int>& arr){

        if(arr.size() == 1) return arr[0];
        if(arr.size() == 2) return max(arr[0], arr[1]);

        int include = arr[0], exclude = 0;
        int prevExclude = 0;
        for(int i = 1; i < arr.size(); i++){
            prevExclude = exclude;
            exclude = max(include, prevExclude);
            include = prevExclude + arr[i];
        }
        return max(include, exclude);
    }
    
public:
    int rob(vector<int>& nums) {
        // return recursive(nums, 0);
        return solveIncExc(nums);
        return solve(nums);
        return tab1(nums);
        return tabulation(nums);
    }
};