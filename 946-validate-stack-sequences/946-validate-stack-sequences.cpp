class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        int p = 0;
        for(auto a: pushed){
            s1.push(a);
            while(!s1.empty() and s1.top()==popped[p]){
                s1.pop();
                p++;
            }
        }
        if(s1.empty()) return true;
        return false;  
    }
};