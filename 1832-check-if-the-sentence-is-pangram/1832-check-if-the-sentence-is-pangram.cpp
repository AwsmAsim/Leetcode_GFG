class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<bool> freqArr(26, false);
        
        for(char ch: sentence){
            freqArr[ch - 'a'] = true;
        }
        
        for(char ch: freqArr){
            if(ch == false) return false;
        }
        
        
        return true;
    }
};