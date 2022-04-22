BST bst = BST();
MyHashMap() {
}
void put(int key, int value) {
bst.insert(key, value);
// cout << " INSERTING " << key << " : " << value << endl;
// bst.inorder(bst.head);
}
int get(int key) {
return bst.search(key);
}
void remove(int key) {
bst.remove(key);
bst.inorder(bst.head);
}
};
​
/**
* Your MyHashMap object will be instantiated and called as such:
* MyHashMap* obj = new MyHashMap();
* obj->put(key,value);
* int param_2 = obj->get(key);
* obj->remove(key);
*/