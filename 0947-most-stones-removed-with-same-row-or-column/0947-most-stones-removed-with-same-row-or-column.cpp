class Solution {
public:
    
    
    unordered_set<int> nodes;
    unordered_map<int, int> rankk;
    unordered_map<int, int> parentt;
    
    int findSet(int i){
        
        
        // cout << i << endl;
        
        if(parentt[i] == i) return i;
        else return parentt[i] = findSet(parentt[i]);
        
    }
    
//     int findSetY(int i, int x){
        
//         if(parentt[i] == x) return x;
//         else return parentt[i] = findSet(i);
//     }
    
    void unionn(int i, int j){
        int x = findSet(i), y = findSet(j);
        
        // cout << "findSet(i): " << x << " findSet(j): " << y << endl;
        
        if(i == j) return;
        if(rankk[x] > rankk[y]){
            parentt[y] = x;
            rankk[x]++;
        }else if(rankk[x] > rankk[y]){
            parentt[x] = y;
            rankk[y]++;
        }else{
            parentt[y] = x;
            rankk[x]++;
        }
        
    }
        
    
    int removeStones(vector<vector<int>>& stones) {
        
        for(vector<int> stone: stones){
            int x = stone[0], y = -(stone[1] + 1);
            // cout << x << ", " << y << endl;            
            
            if(parentt.find(x) == parentt.end()){
                parentt[x] = x;
                rankk[x] = 0;
                ++rankk[x];
            }
            if(parentt.find(y) == parentt.end()){
                parentt[y] = x;
                // rankk[x] = 0;
                ++rankk[x];
            }
            
            unionn(x, y);
        }
        
        unordered_set<int> set1;
        
        for(pair<int, int> p: parentt){
            // cout << p.first << " : " << p.second << endl;
            set1.insert(findSet(p.first));
        }
        
        return (stones.size() - set1.size());
        
        
    }
};