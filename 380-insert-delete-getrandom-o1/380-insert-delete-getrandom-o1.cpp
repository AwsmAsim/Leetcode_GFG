class RandomizedSet {
    unordered_map<int, int> hMap;
    vector<int> v1;
    void printList(vector<int> v1){
        for(auto a: v1) cout << a << " ";
        cout << endl;
    }
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hMap.find(val) != hMap.end()){
            return false;
        }
        v1.push_back(val);
        hMap[val] = v1.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hMap.find(val) != hMap.end()){
            if(v1[v1.size()-1] == val) v1.pop_back();
            else{
                // printList(v1);
                // cout << "last element: " << v1[v1.size()-1] << endl;
                // cout << "hMap[val]: " << hMap[val] << endl;
                v1[hMap[val]] = v1[v1.size()-1];
                hMap[v1[v1.size()-1]] = hMap[val];
                v1.pop_back();
            }
            // printList(v1);
            hMap.erase(val);
            // v1.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random = rand()%v1.size();
        return v1[random];
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */