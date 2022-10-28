class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagMap;
        
        for(string str: strs){
            string temp = str;
            sort(str.begin(), str.end());
            anagMap[str].push_back(temp);
        }
        
        vector<vector<string>> answer;
        
        for(pair<string, vector<string>> p: anagMap){
            answer.push_back(p.second);
        }
        
        return answer;
    }
};