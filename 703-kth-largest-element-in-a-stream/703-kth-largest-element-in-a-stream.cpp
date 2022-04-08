class KthLargest {
    
    void printPQ(priority_queue<int, vector<int>, greater<int>> pq){
        priority_queue<int, vector<int>, greater<int>> pq1 = pq;
        cout << "priority queue: ";
        while(pq1.size()){
            cout << pq1.top() << " " << endl;
            pq1.pop();
        }
        cout << endl;
    }
    
    
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k1=-1;
    
    KthLargest(int k, vector<int>& nums) {
        int i = 0;
        this->k1 = k;
        while(k and i<nums.size()){
            pq.push(nums[i]);
            --k; ++i;
        }
        while(i < nums.size()){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            } 
            ++i;
        }
        // printPQ(pq);
    }
    
    int add(int val) {
        if(pq.empty()){
            pq.push(val);
            return pq.top();
        }
        if(pq.size()<k1){
            pq.push(val);
            // printPQ(pq);
        }else 
        if(val > pq.top()){
            pq.pop();
            pq.push(val);
            // printPQ(pq);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */