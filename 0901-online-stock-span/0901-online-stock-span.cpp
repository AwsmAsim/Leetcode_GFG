class StockSpanner {
public:
    
    vector<int> list;
    
    int findLeast(int num){
        int n = list.size(), count = 1;
        for(int i = n - 1; i >= 0; i--){
            if(num < list[i]) return count;
            else ++count;
        }
        
        return count;
    }
    
    
    
    StockSpanner() {
        
    }
    
    int nextNaive(int price) {
        int ans = findLeast(price);
        list.push_back(price);
        return ans;
    }
    
    void _print(stack<pair<int, int>> s1){
        
        while(!s1.empty()){
            int first = s1.top().first, second = s1.top().second;
            cout << "(" << first  << ", " << second << "), ";
            s1.pop();
        }
        cout << endl;
    }
    
    stack<pair<int, int>> s1;
    int next(int price) {
        int count = 1;
        while(!s1.empty() and s1.top().first <= price){
            count += s1.top().second;
            s1.pop();
        }
        s1.push(pair<int, int>(price, count));
        
        // // Print stack 
        // _print(s1);
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */