class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n == 1) return true;
        int twosCompliment = (n&~(n-1));
        int rightMostSetBitPostition = log(twosCompliment)/log(2); // Finding log base 2
        
        // cout << "Right most set bit: " << rightMostSetBitPostition << endl;
        
        if(((n&(n-1)) == 0) and (rightMostSetBitPostition%2 == 0)) return true;
        
        return false;
    }
};