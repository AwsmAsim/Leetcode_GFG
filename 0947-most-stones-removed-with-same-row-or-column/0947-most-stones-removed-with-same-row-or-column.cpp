class Solution {
    
    
public:
    
    unordered_map<int, int> parent;
    unordered_map<int, int> rankk;
    int islands = 0;
    
    int find(int i){
        
        if(!parent.count(i)){
            parent[i] = i;
            rankk[i] = 1;
            return i;
        }
        
        if(parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
        
    }
    
    void unionn(int i, int j){
        
        int x = find(i);
        int y = find(j);
        if(x==y) return;
        
        if(x < 0){
            parent[x] = y;
        }else if(y < 0){
            parent[y] = x;
        }else{
            if(rankk[x] > rankk[y]){
                parent[y] = x;
                return;
            }else if(rankk[x] < rankk[y]){
                parent[x] = y;
                return;
            }else{
                parent[x] = y;
                ++rankk[y];
                return;
            }
        }
        
        
    }
    
    
    int removeStones(vector<vector<int>>& stones) {
        
        for(auto stone: stones){
            unionn(stone[0], ~stone[1]);
        }
        
        unordered_set<int> set1;
        
        for(pair<int ,int> p: parent){
            set1.insert(find(p.first));
        }
        
        // for(int pp: set1) {
        //     cout << pp << ", ";
        // }
        // cout << endl;
        
        return stones.size() - set1.size();
        
    }
};













