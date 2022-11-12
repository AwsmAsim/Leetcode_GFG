class MedianFinder {
public:
    
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int i = 0;
    
    MedianFinder() {
        
    }
    
    void _print(priority_queue<int, vector<int>> pq){
        while(!pq.empty()){
            cout << pq.top() << ", ";
            pq.pop();
        }
        cout << endl;
    }
    
    void _print(priority_queue<int, vector<int>, greater<int>> pq){
        while(!pq.empty()){
            cout << pq.top() << ", ";
            pq.pop();
        }
        cout << endl;
    }
    
    void addNum(int num) {
        if(left.size() == 0 and right.size() == 0){
            left.push(num);
            return;
        }
        int num1 = num; // debug
        
        if((left.size() >= 1 and num < left.top()) or right.size() == 0){
            left.push(num);
        }else if((right.size() and num > right.top()) or left.size() == 0){
            right.push(num);
        }else{
            left.push(num);
        }
        
        int sLeft = left.size(), sRight = right.size();
        
        if(abs(sLeft - sRight) > 1){
            
            // cout << 
            
            if(sLeft > sRight){
                num = left.top();
                left.pop();
                right.push(num);
            }else{
                num = right.top();
                right.pop();
                left.push(num);
            }
        }
        // ++i;
        // if(i < 10){
        //     cout << num1 << endl;
        //     cout << "left: ";
        //     _print(left);
        //     cout << "right: ";
        //     _print(right);
        //     cout << endl;
        // }
        
    }
    
    double findMedian() {
        
        int sLeft = left.size(), sRight = right.size();
        if(sLeft == sRight){
            double summ = left.top() + right.top();
            return (summ / 2.0);
        }else{
            if(sLeft < sRight){
                return right.top();
            }else return left.top();
        }
        
        return -1;
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */