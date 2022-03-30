class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        vector<int> v;
        int a, b, c, d;
        
        for(int i = 0; i< nums.size(); i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int r = target - nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(j>i+1 and nums[j] == nums[j-1]) continue;
                int r1 = r - nums[j];
                int l = j+1;
                int r = nums.size()-1;
                while(l<r){
                    v = {};
                    if(nums[l] + nums[r] == r1){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        answer.push_back(v);
                        if(nums[l]==nums[r]) break;
                        else{
                            int x = nums[l];
                            int y = nums[r];
                            while(x == nums[l]) ++l;
                            while(y == nums[r]) --r;
                        }
                    }
                    else if(nums[l]+nums[r] < r1) l++;
                    else --r;
                }
            }
        }
        
        
        return answer;
    }
};