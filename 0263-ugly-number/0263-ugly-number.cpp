class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        vector<int> primes = {2, 3, 5};
        
        for(int prime: primes){
            while( n != 1 and n%prime ==0){
                n = n/prime;
            }
        }
        
        if(n > 1) return false;
        return true;
        
    }
};