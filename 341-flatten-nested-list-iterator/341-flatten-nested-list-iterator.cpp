/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    
    void flattenlist(vector<NestedInteger> nestedList, vector<int>& flatList){
        
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger()) {
                flatList.push_back(nestedList[i].getInteger());
            }
            else flattenlist(nestedList[i].getList(), flatList);
        }
        
        return;
    }
    int itr = 0;
    
public:
    vector<int> flatList;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenlist(nestedList, flatList);
        // for(auto a: flatList) cout << a << ", ";
        // cout << "\n";
    }
    
    int next() {
        int num = flatList[itr];
        itr++;
        return num; 
    }
    
    bool hasNext() {
        if(itr>=flatList.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */