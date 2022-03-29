class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t=nums[0], r=nums[0], firstRun = 1;
        while(firstRun or (t!=r)){
            t = nums[t];
            r = nums[nums[r]];
            firstRun = 0;
            // cout << "tortoise: " << t << ", rabbit: " << r << endl;
        }
        t = nums[0];
        while(t!=r){
            t = nums[t];
            r = nums[r];
        }
        return r;
    }
};