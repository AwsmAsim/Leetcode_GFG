class Solution {
    
    int solve(int startValue, int target){
        int count = 0;
        while(target!=startValue){
            if(target < startValue){
                return count + (startValue-target);
            }
            else if(target&1){
                target += 1;
            }else{
                target /= 2;
            }
            count++;
        }
        return count;
    }
    
public:
    int brokenCalc(int startValue, int target) {
        return solve(startValue, target);
    }
};