class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int a: nums) x ^= a;
        
        int d = (x & (-1 * (unsigned int)x));
        int y1 = 0, y2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if((nums[i]&d) != 0){
                y1 = y1 ^ nums[i];
            } 
        }
        
        y2 = x ^ y1;
        
        
        return {y1, y2};
        
        
    }
};