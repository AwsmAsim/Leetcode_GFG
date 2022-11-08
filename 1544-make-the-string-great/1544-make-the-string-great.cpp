class Solution {
    
    string solve(string& str1){
        
        bool changed = false;
        int diff = 'A' - 'a';
        // cout << "diff: " << diff << endl;
        
        for(int i = 0; i < str1.size(); i++){
            int curr = str1[i], next;
            int i1 = i;
            // cout << "i1: " << i1 << ", i: " << i << endl; 
            while(i < str1.size() - 2 and str1[i+1] == 0) ++i;
            next = str1[i+1];
            if(curr + diff == next or curr - diff == next){
                changed = true;
                str1[i1] = 0;
                str1[i+1] = 0;
                // cout << "str1[" << i1 << "] = " << str1[i1] << " str1[" << i+1 << "]: "<< str1[i+1] << endl; 
                // cout << str1 << endl;
            }
        }
        
        if(!changed) return str1;
        else return solve(str1);
        
        
    }
    
public:
    string makeGood(string s) {
        
        string s1 = solve(s);
        string answer;
        for(char ch: s1){
            if(ch != 0) answer.push_back(ch);
        }
        return answer;
    }
};