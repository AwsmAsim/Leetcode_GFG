class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freqArr(27,1000001);
        
        for(int i = 0; i < s.size(); i++){
            if(freqArr[s[i] - 'a'] == 1000001) freqArr[s[i] - 'a'] = i;
            else freqArr[s[i] - 'a'] = INT_MAX;
        }
        
        int minFirst = INT_MAX;
        for(int num: freqArr) minFirst = min(minFirst, num);
        
        if(minFirst == 1000001) return -1; // No unique characters
        return minFirst;
    }
};