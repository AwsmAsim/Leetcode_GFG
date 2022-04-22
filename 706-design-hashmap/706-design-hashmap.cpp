class MyHashMap {
    vector<int> hSet = vector<int>(1000001, -1);
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hSet[key] = value;
    }
    
    int get(int key) {
        return hSet[key];
    }
    
    void remove(int key) {
        hSet[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */