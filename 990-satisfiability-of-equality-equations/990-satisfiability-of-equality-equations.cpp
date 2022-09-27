class Solution {
    
    // a = 1 ... z = 25
    
    vector<int> rankk;
    vector<int> parent;
    
    void makeSet(){
        for(int i = 0; i < 26; i++) parent[i] = i;
    }
    
    int findSet(int i){
        if(i == parent[i]){
            return i;
        }
        
        return parent[i] = findSet(parent[i]);
    }
    
    void unionn(int i, int j){
        int u = findSet(i);
        int v = findSet(j);
        if(u==v) return;
        
        if(rankk[u] < rankk[v]){
            parent[u] = v;
        }else if(rankk[v] < rankk[u]){
            parent[v] = u;
        }else{
            parent[u] = v;
            ++rankk[v];
        }
    }
    
    bool hasSameSet(int i, int j){
        if(i==j) return true;
        if(findSet(i) == findSet(j)) return true;
        return false;
    }
    
public:
    
    Solution(){
        rankk.resize(26,0);
        parent.resize(26,0);
    }
    
    bool equationsPossible(vector<string>& equations) {
        makeSet();
        vector<string> equals;
        for(string str: equations){
            int n1 = str[0] - 'a';
            int n2 = str[3] - 'a';
            if(str[1] == '='){
                unionn(n1, n2);
            }
        }
        for(string eq: equations){
            int n1 = eq[0] - 'a';
            int n2 = eq[3] - 'a';
            if(eq[1] == '!'){
                if(hasSameSet(n1, n2)) return false;
            }
        }
        
        return true;
    }
};










