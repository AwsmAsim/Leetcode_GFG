class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum1 = INT_MAX, left, right;
        int closestSum = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++){
            left = i+1;
            right = nums.size()-1;
            while(left < right){
                sum1 = nums[i] + nums[left] + nums[right];
                // cout << nums[i] << " " << " " << nums[left] << " " << nums[right] << endl;
                // cout << sum1 << endl;
                if(abs(target-sum1) < abs(closestSum)){
                    closestSum = target-sum1;
                }
                // cout << "closest sum: " << closestSum << endl;
                if(sum1>target) --right;
                else if(nums[left] + nums[right] + nums[i]==target) return target;
                else ++left;
            }
        }
        
        return target - closestSum;
    }
};