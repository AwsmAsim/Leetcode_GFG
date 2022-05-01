class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int j = 0, k = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                j--;
                j = max(0,j);
            }else{
                s[j]=s[i];
                j++;
            }
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i]=='#'){
                k--;
                k = max(0,k);
            }else{
                t[k] = t[i];
                ++k;
            }
        }
        
        if(j!=k) return false;
        
        for(int i = 0; i < k; i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};