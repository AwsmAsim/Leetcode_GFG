class Solution {
    
    string subStr(string& str, int begin, int end){
        string outputStr;
        for(int i = begin; i <= end; i++){
            outputStr.push_back(str[i]);
        }
        
        return outputStr;
    }
    
public:
    bool hasAllCodes(string s, int k) {
        int wStart = 0, wEnd = k - 1;
        if(wEnd > s.size()-1) return false;
        // cout << "wEnd: " << wEnd << endl;
        int quantity = ((int) (pow(2,k)));
        // cout << "quantity: " <<  quantity << endl;
        // vector<bool> arr(quantity, false);
        unordered_set<string> numSet;
        for(; wEnd < s.size(); wEnd++){
            numSet.insert(subStr(s, wStart, wEnd));
            // cout << s.substr(wStart, wEnd) << ", " << endl;
            ++wStart;
        }
        // cout << endl;
        // for(auto num: numSet) cout << num  << ", ";
        // cout << endl;
        
        if(numSet.size() == quantity) return true;
        return false;
        
    }
};