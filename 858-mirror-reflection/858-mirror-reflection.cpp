class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2 == 0 and q%2 == 0) {
            p/=2;
            q/=2;
        }
        if(p%2 == 0 and q&1) return 2;
        if(q%2 == 0 and p&1) return 0;
        else return 1;
        return 0;
    }
};