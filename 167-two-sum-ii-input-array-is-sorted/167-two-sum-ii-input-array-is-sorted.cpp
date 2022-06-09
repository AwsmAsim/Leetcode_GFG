class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size()-1;
        
        while(p1 < p2){
            int sum1 = numbers[p1] + numbers[p2]; 
            if( sum1 == target) return {p1 + 1, p2 + 1};
            if(sum1  < target) ++p1;
            else --p2;
        }
        
        return {};
    }
};