class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        queue<int> poppedQ;
        for(auto a: popped) poppedQ.push(a);
        for(auto a: pushed){
            s1.push(a);
            while(!s1.empty() and s1.top()==poppedQ.front()){
                s1.pop();
                poppedQ.pop();
            }
        }
        if(s1.empty()) return true;
        return false;
        
    }
};