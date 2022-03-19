class FreqStack {
    
    class FreqIdx{
        public:
        int element;
        int frequency;
        int idx;
        
        FreqIdx(int element, int frequency, int idx){
            this->element = element;
            this->frequency = frequency;
            this->idx = idx;
        }
    };
    
    struct comparator{
        bool operator()(const FreqIdx& a, const FreqIdx& b){
            if(a.frequency==b.frequency){
                return a.idx < b.idx;
            }else return a.frequency < b.frequency;
        }
    };
    
    
    unordered_map<int, int> freq;
    int idx = 0;
    priority_queue<FreqIdx, vector<FreqIdx>, comparator> pq;
    public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        pq.push(FreqIdx(val, freq[val], idx));
        idx++;
        
//         for(auto a: indexes){
//             cout << a.first << ": {" ;
//             for(auto idx: a.second) cout << idx << ", ";
//             cout << "} \n";
//         }
        
//         cout << endl;
    }
    
    int pop() {
        FreqIdx f = pq.top();
        pq.pop();
        freq[f.element]--;
        return f.element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */