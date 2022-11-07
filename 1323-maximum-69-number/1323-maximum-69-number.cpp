class Solution {
    
    string toString(int num){
        string ans;
        while(num){
            ans.push_back('0' + num%10);
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int toInt(string s){
        int num = 0; 
        for(char ch: s){
            num = 10*num + (ch - '0');
        }
        return num;
    }
    
public:
    int maximum69Number (int num) {
        string s;
        s = toString(num);
        // cout << s << endl;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                // cout << s << endl;
                return toInt(s);
            }
        }
        
        return num;
        
    }
};