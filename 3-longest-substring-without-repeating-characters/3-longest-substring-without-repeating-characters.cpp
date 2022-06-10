class Solution {
    
    void printSet(unordered_set<char> set1){
        for(auto a: set1){
            cout << a << ", ";
        }
        cout << endl;
    }
    
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        
        int wStart = 0, wEnd = 0, wSize = wEnd - wStart + 1, maxSize = 0;
        unordered_set<char> cDuplicates;
        
        while(wEnd < s.size()){
            
            while(cDuplicates.find(s[wEnd]) != cDuplicates.end()){
                cDuplicates.erase(s[wStart]);
                ++wStart;
            }
            
            cDuplicates.insert(s[wEnd]);
            // printSet(cDuplicates);
            
            wSize = cDuplicates.size();
            // cout << wSize << endl;
            
            maxSize = max(maxSize, wSize);
            
            // cout << "maxSize: " << maxSize << endl;
            
            ++wEnd;
        }
        
        return maxSize;
    }
};