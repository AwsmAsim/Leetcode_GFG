class Solution {
public:
    bool validPalindrome(string s) {
        int st = 0;
        int lt = s.size()-1;
        int count = 0;
        
        while(st<=lt){
            if(s[st]==s[lt]){
                st++;
                lt--;
            }
            else {
                st++;
                count++;
            }
        }
    int count1 = 0;
        st=0;
        lt = s.size()-1;
                while(st<=lt){
            if(s[st]==s[lt]){
                st++;
                lt--;
            }
            else {
                lt--;
                count1++;
            }
        }
        if(count1<=1||count<=1){
            return true;
        }
        else return false;

    }
};