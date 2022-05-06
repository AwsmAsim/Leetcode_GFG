class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> s1;
        for(int i = 0; i < s.size(); i++){
            if(s1.size()==0 or s1.top().first != s[i]){
                s1.push({s[i], 1});
                // cout << s[i] << " ";
            } 
            else{
                if(s1.top().second == k-1) s1.pop();
                else {
                    int count = s1.top().second;
                    s1.pop();
                    s1.push({s[i], ++count});
                }
            }
        }
        
        string answer = "";
        while(!s1.empty()){
            for(int i = 0; i < s1.top().second; i++){
                answer += s1.top().first;
            }
            s1.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
        
    }
};