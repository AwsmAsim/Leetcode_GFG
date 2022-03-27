class Solution {
    
    void printList(vector<int> lst){
        for(auto a: lst) cout << a  << " " ;
        cout << endl;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> answer;
        vector<int> visited(mat.size(), 0);
        int breakLoop = 0;
        // cout << "size: " << mat[0].size() << endl;
        for(int j = 0; j < mat[0].size() and k >0; j++){
            for(int i = 0; k > 0 and i < mat.size(); i++){
                // cout << "i: " << i << " j: " << j <<endl;
                // if(j>mat[i].size()-1) break;
                if(visited[i]) continue; 
                if(mat[i][j] == 0){
                    answer.push_back(i);
                    visited[i] = 1;
                    --k;
                }
            }
        }
        int i = 0;
        while(k and i < mat.size()){
            if(visited[i]){
                ++i;
                continue;
            } 
            answer.push_back(i);
            ++i;
            --k;
            // cout << i << " " << k << endl;
        }
        
        
        return answer;
        
    }
};