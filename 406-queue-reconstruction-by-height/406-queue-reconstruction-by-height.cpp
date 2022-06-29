class Solution {
    
    static bool comparator(const vector<int>& v1, const vector<int>& v2){
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int initialIdx = 0;
        vector<vector<int>> answer(people.size(), vector<int>(2, -1));
        
        sort(people.begin(), people.end(), comparator);
        
        // // sorted people array 
        // for(vector<int> ppl : people){
        //     cout << "[" << ppl[0] << "," << ppl[1] << "],";
        // }
        // cout << endl;
        
        for(vector<int> ppl: people){
            int k = ppl[1], h = ppl[0];
            
            for(int i = 0; i < answer.size(); i++){
                
                if(answer[i][0] != -1 and answer[i][0] < h) continue;
                if(answer[i][0] == -1){
                    if(k == 0){
                        answer[i] = ppl;
                        break;
                    } 
                    else --k;
                }
                else if(answer[i][0] >= h){
                    --k;
                }
            }
        }
        
        return answer;
    }
};