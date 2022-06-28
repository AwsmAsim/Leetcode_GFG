class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMap;
        unordered_map<int, bool> availableMap;
        vector<int> countList;
        int del = 0;
        
        for(char ch: s) ++freqMap[ch];
        
        for(auto val: freqMap){
            availableMap[val.second] = true;
            countList.push_back(val.second);
        }
        
        sort(countList.begin(), countList.end(), greater<int>());
        
//         // freq Map
//         for(auto val: freqMap){
//             cout << val.first << ": " << val.second << ",  ";
//         }
//         cout << endl;
        
//         // available Map
//         for(auto val: availableMap) cout << val.first << ": " << val.second << ",  ";
//         cout << endl;
        
//         // Count List
//         cout << "{ ";
//         for(auto c: countList) cout << c << ", ";
//         cout << "} " << endl;
        
        
        if(availableMap.size() == freqMap.size()) return 0;
        
        for(int i = 0; i < countList.size(); i++){
            if(availableMap[countList[i]]) availableMap[countList[i]] = false;
            else{
                
                // cout << "index: " << i  << ": " << endl;
                while(availableMap.find(countList[i]) != availableMap.end()){
                    --countList[i];
                    ++del;
                    // cout << "\tcountList[" << i << "]: " << countList[i] << " del: " << del << endl;
                    if(countList[i] == 0) break;
                    
        //             for(auto val: availableMap) cout << val.first << ": " << val.second << ",  ";
        // cout << endl;
                }
                availableMap[countList[i]] = false;
            }
        }
        
        return del;
        
        
    }
};