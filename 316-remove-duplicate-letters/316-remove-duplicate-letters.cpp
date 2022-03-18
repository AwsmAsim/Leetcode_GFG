class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> sElements;
        unordered_map<char, int> lastIndex;
        string s2 = "";
        
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i]] = i;
        }
        
        stack<char> s1;
        for(int i = 0; i<s.size(); i++){
            while(!s1.empty() and s1.top()>s[i] and lastIndex[s1.top()]>i and sElements[s[i]] == 0){
                sElements[s1.top()]--;
                s1.pop();
            } 
            if(sElements[s[i]]==0){
                s1.push(s[i]);
                sElements[s[i]]++;
                // cout << " Top: " << s1.top() << s1.size() << "\t";
            }
        }
        // cout << endl;
        while(!s1.empty()){
            // cout << "Currently on element: " << s1.top() << "\n";
            s2 += s1.top();
            s1.pop();
        }
        
        reverse(s2.begin(), s2.end());
        
        return s2;
            
    }
};