class Solution {
    
    bool isSubString(string s){
        int n = s.size();
        for(int i = 0; i  < n/2; i++){
            if(s[i] != s[n-i-1]) return false;    
        }
        return true;
    }
    
public:
    int removePalindromeSub(string s) {
        if(isSubString(s))return 1;
        else return 2;
    }
};