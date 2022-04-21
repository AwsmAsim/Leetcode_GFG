class MyHashSet {
public:
    const int SIZE = 769;
    
    list<int> ll[769];
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(ll[key%SIZE].begin(),ll[key%SIZE].end(),key)==ll[key%SIZE].end())
            ll[key%SIZE].push_back(key);
    }
    
    void remove(int key) {
        if(find(ll[key%SIZE].begin(),ll[key%SIZE].end(),key)!=ll[key%SIZE].end())
            ll[key%SIZE].remove(key);
    }
    
    bool contains(int key) {
        if(find(ll[key%SIZE].begin(),ll[key%SIZE].end(),key)!=ll[key%SIZE].end()) return true;
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