class Solution {
    
    bool canMutate(string& str1, string& str2){
        int distinct = 0;
        int n = str1.size();
        for(int i = 0; i < n; i++){
            if(str1[i] != str2[i]) ++distinct;
            if(distinct > 1) return false;
        }
        return true;
    }
    
    int solveRec(string start, string& end, set<int>& used, vector<string>& bank){
        
        if(start == end) return 0;
        if(used.size() == bank.size()) return INT_MAX;
        
        int nBank = bank.size();
        int ans = INT_MAX;
        
        for(int i = 0; i < nBank; i++){
            if(used.find(i) != used.end()) continue;
            if(canMutate(start, bank[i])){
                used.insert(i);
                int cAns = solveRec(bank[i], end, used, bank);
                used.erase(i);
                if(cAns == INT_MAX) continue;
                ans = min(ans, 1 + cAns);
            }
        }
        
        return ans;
    }
    
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // AAAAACCC
        // AACCCCCC
        
        // ["AAAACCCC","AAACCCCC","AACCCCCC"]
        vector<int> distinctIdx;
        // vector<int> counter(bank.size(), 0);
        // map<int, set<int>> hMap;  
        
        for(int i = 0; i < start.size(); i++){
            if(start[i] != end[i]) distinctIdx.push_back(i);
        }

        if(distinctIdx.size() == 0) return 0;
        
        // False Reasons
        bool isValid = false;
        for(string str: bank){
            if(str == end) isValid = true;
        } 
        if(!isValid) return -1;
        if(distinctIdx.size() > bank.size()) return -1;
        
        set<int> used;
        int ans =  solveRec(start, end, used, bank);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};