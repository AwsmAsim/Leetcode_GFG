class Solution {
    static bool sortCol(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> initialIdx, finalIdx;
        vector<int> answer;
        
        for(int i = 0; i<s.size(); i++) finalIdx[s[i]] = i;
        for(int i = s.size()-1; i>=0; i--){
            initialIdx[s[i]] = i;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(answer.size()==0) answer.push_back(finalIdx[s[i]]);
            else if(finalIdx[s[i]] > answer.back()){
                // cout << finalIdx[s[i]] << " " << answer.back() << endl;
                if(initialIdx[s[i]] < answer.back()){
                    answer[answer.size()-1] = finalIdx[s[i]];
                }else answer.push_back(finalIdx[s[i]]);
            }
        }
        
        
        for(int i = answer.size()-1; i>0; i--) answer[i] -= answer[i-1];
        answer[0] += 1;
        return answer;
        
    }
};