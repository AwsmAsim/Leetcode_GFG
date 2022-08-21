class Solution {
    
    
    bool canReplace(string stamp, string target, int i){
        int j = -1, i1 = i;
        for(;i < (i1 + stamp.size()); i++){
            ++j;
            if(target[i] == '?') continue;
            if(target[i] != stamp[j]) return false;
        }
        return true;
    }
    
    void replace(string& stamp, string& target, int& count, int i){
        int j =-1, i1 = i;
        // // cout << "i1 + stamp.size(): " << (i1 + stamp.size()) << endl; 
        for(; i < (i1 + stamp.size()); i++){
            ++j;
            if(target[i] == '?') continue;
            target[i] = '?';
            ++count; 
        }
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
       
        string target1 = target;
        int count = 0;
        vector<int> visited(target.size(), 0);
        bool changesMade = false;
        vector<int> answer;
        
        while(count != target.size()){
            changesMade = false;
            for(int i = 0; i <= (target.size() - stamp.size()); i++){
                if(!visited[i] and canReplace(stamp, target1, i)){
                    replace(stamp, target1, count, i);
                    answer.push_back(i);
                    visited[i] = changesMade = true;
                }
                // cout << count << endl;
                if(count == target.size()) break;
            }
            if(!changesMade) return {};
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};