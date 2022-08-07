class LRUCache {
    
public:
    
    int capacity;
    
    class DLL{
        public:
        int key;
        int val;
        DLL* prev;
        DLL* next;
        
        DLL(int key, int val){
            this-> key = key;
            this->val = val;
        }

    };
    
    unordered_map<int, DLL*> hMap; 
    DLL *head, *tail;
    
    DLL* insertAtStart(int key, int val){
        
        DLL* next = head->next;
        DLL* node = new DLL(key, val);
        head->next = node;
        
        node->prev = head;
        node->next = next;
        
        next->prev = node;
        return node;
        
    }
    
    DLL* removeLast(){
        DLL* nodeToBeDeleted = tail->prev;
        DLL* prev = nodeToBeDeleted->prev;
        prev->next = nodeToBeDeleted->next;
        tail->prev = prev;
        return nodeToBeDeleted;
    }
    
    void removeNode(DLL* node){
        DLL* prev = node->prev;
        DLL* next = node->next;
        prev->next = next;
        next->prev = prev;
        // cout << (prev->key) << "->" << (prev->next->key) << "\n" << (next->key) << "p-> " << (next->prev->key) << endl;
        node->next = node->prev = NULL;
    }
    
    void printDLL(){
        DLL* t = head;
        t = t->next;
        while(t != tail){
            cout << (t->key) << ":" << (t->val) << ", ";
            t = t->next;
        }
        cout << endl;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLL(-1, -1);
        tail = new DLL(100001, 100001);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        // Delete the present node and insertt from the start;
        if(hMap.find(key) == hMap.end()) return -1;
        int valToBeReturned = hMap[key]->val;
        removeNode(hMap[key]);
        DLL* node = insertAtStart(key, valToBeReturned);
        hMap[key] = node;
        // printDLL();
        return valToBeReturned;
    }
    
    void put(int key, int value) {
        // INsert from the start.
        if(hMap.find(key)!=hMap.end()) removeNode(hMap[key]);
        else if(hMap.size()==capacity){
            DLL* lastNode = removeLast();
            hMap.erase(lastNode->key);
            // delete(lastNode);
        }
        
        DLL* node = insertAtStart(key, value);
        hMap[key] = node;
        // printDLL();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */