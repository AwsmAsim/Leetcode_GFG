class Solution {
public:
    
    void printGraph(unordered_map<string, unordered_set<string>> graph){
        for(pair<string, unordered_set<string>> p: graph){
            cout << p.first << ": ";
            for(string nbr: p.second){
                cout << nbr << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int graphSolve(vector<string>& arr){
        unordered_map<string, unordered_set<string>> graph;
        unordered_set<string> visited;
        vector<string> nodes;
        
        for(string str: arr){
            string temp = "";
            for(int i = 0; i < str.size(); i++){
                temp.push_back(str[i]);
                nodes.push_back(temp);
                if(temp.size()!=str.size())
                graph[temp].insert(str);
            }
        }
        printGraph(graph);
        
        cout << "nodes: " << endl;
        for(string n: nodes){
            cout << n << ", ";
        }
        cout << endl;
        
        int mSize = 0;
        int answer = 0;
        
        for(string n: nodes){
            mSize = 0;
            
            if(visited.find(n) == visited.end()){
                queue<string> Q;
                Q.push(n);
                while(!Q.empty()){
                    string currentStr = Q.front();
                    Q.pop();
                    visited.insert(currentStr);
                    mSize = max(mSize, (int)currentStr.size());
                    for(auto nbr: graph[currentStr]){
                        if(visited.find(nbr) == visited.end()){
                            Q.push(nbr);
                        }
                    }
                }
                
                answer += mSize;
                mSize = 0;
            }
        }
        
        return answer;
    }
    
    bool hasDuplicate(string s1, string s2){
        unordered_set<char> stringSet;
        
        for(char ch: s1) stringSet.insert(ch);
        for(char ch: s2){
            if(stringSet.find(ch) != stringSet.end()) return true;
        }
        
        return false;
    }
    
    bool haveRepetedCharacteres(string str){
        unordered_set<char> charSet;
        for(char ch: str){
            if(charSet.find(ch) != charSet.end()) return true;
            charSet.insert(ch);
        }
        return false;
    }
    
    int backtracking(int idx, string& s, vector<string>& arr){
        
        // cout << idx << " " << s << endl;
        if(idx >= arr.size()) return s.size();
        if(haveRepetedCharacteres(arr[idx])) return backtracking(idx+1, s, arr);
        
        // s.push_back(arr[idx]);
        int pick  = -1, notPick = 0;
        string s1 = s + arr[idx];
        
        if(!hasDuplicate(s, arr[idx]))
        pick = backtracking(idx + 1, s1, arr);
        
        notPick = backtracking(idx + 1, s, arr);
        
        return max(pick, notPick);
        
    }
    
    int maxLength(vector<string>& arr) {
        string s;
        return backtracking(0, s, arr);
    }
};