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
    
    int next(int price) {
        int ans = findLeast(price);
        list.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */