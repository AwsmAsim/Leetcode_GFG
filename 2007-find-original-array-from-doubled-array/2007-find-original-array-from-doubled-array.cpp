class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> hMap;
        unordered_map<int, int> answerMap;
        
        for(int num: changed) hMap[num]++;
        
        // [1, 1, 2, 2, 2, 4]
        // {1: 2, 2: 3, 4: 1}
        // {1:0, 2: 1, 4: 1}
        // {1:0, 2:0, 4:0}
        
        for( auto itr: hMap){
            int cCount = itr.second;
            
            if(itr.first == 0){
                if(itr.second&1) return vector<int>();
                answerMap[0] = itr.second/2;
                hMap[0] = 0;
            }
            if(cCount == 0) continue;
            if(hMap.find(itr.first*2)==hMap.end()) return vector<int>();
            
            if(hMap[itr.first*2] >= cCount){
                hMap[itr.first*2] -= cCount;
                answerMap[itr.first] = hMap[itr.first];
                hMap[itr.first] = 0;
            }
        }
        
        // Double check
        for(auto itr: hMap){
            if(itr.second != 0) return vector<int>();
        }
        
        vector<int> answer;
        for(auto itr: answerMap){
            for(int j = 0; j < itr.second; ++j){
                answer.push_back(itr.first);
            }
        }
        
        return answer;
        
    }
};