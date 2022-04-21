class MyHashSet {
public:
    
    vector<int> hSet = vector<int>(1000001, 0);
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        hSet[key] = 1;
    }
    
    void remove(int key) {
        hSet[key] = 0;
    }
    
    bool contains(int key) {
        if(hSet[key]==1) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */