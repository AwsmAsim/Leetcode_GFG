class Solution {

    int solve(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int p1=0, p2=nums.size()-1, count = 0;
        while(p1<=p2){
            if((nums[p1] + nums[p2]) <= target){
                p1++;
                p2--;
                count++;
            }else{
                p2--;
                count++;
            }
        }
        
        return count;
    }
    
public:
    int numRescueBoats(vector<int>& people, int limit) {
        return solve(people, limit);
    }
};