class Solution {
    int binarySearch(int target, int left, int right, vector<int>& nums){
        if(left > right) return -1;
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarySearch(target, left, mid-1, nums);
        else return binarySearch(target, mid + 1, right, nums);
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(target, 0, nums.size()-1, nums);
    }
};