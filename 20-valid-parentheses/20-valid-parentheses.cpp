class Solution {
public:
    bool isValid(string s) {
        stack<int> s1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                s1.push(s[i]);
            }else{
                if(s1.size()>0 and (s1.top()=='(' and s[i]==')' or s1.top()=='{' and s[i]=='}' or s1.top()=='[' and s[i]==']'))
                    s1.pop();
                else s1.push(s[i]);
            }
        }
        
        if(s1.size()==0) return true;
        else return false;
    }
};