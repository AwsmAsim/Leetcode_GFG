class Solution {
public:
    
    void printSearchDict(unordered_map<string, unordered_set<string>> searchMap){
        for(auto word: searchMap){
            cout << word.first << ": ";
            for(auto wordInSet:  word.second){
                cout << wordInSet << ", ";
            }
            cout << endl;
        }
    }
    
    vector<string> setsToSortedVector(unordered_set<string> set1){
        vector<string> sortedVector;
        for(auto str: set1){
            sortedVector.push_back(str);
        }
        sort(sortedVector.begin(), sortedVector.end());
        return sortedVector;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, unordered_set<string>> searchMap;
        vector<vector<string>> answer;
        
        for(auto word: products){
            string newWord;
            
            for(char ch: word){
                newWord.push_back(ch);
                searchMap[newWord].insert(word);
            }
            
        }
        
        // printSearchDict(searchMap);
        
        string searchWordTyped;
        for(char letterTyped: searchWord){
            // traversing each letter from the searchWord
            searchWordTyped.push_back(letterTyped); 
            vector<string> currentResultsObtained;// results from current word
            
            vector<string> sortedResults;
            sortedResults = setsToSortedVector(searchMap[searchWordTyped]);
            int wordCount = 0;
            // Search the words set from searchMap for current typed value
            for(auto result: sortedResults){
                
                // for(string result: results){
                currentResultsObtained.push_back(result);
                ++wordCount;
                if(wordCount >= 3) break;
            }
            answer.push_back(currentResultsObtained);
        }
        
        return answer;
    }
};