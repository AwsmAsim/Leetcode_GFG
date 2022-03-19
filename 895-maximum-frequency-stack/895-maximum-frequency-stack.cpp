class FreqStack {
    
    class FreqIdx{
        public:
        int element;
        int frequency;
        vector<int> idx;
        int topIdx = -1;
        
        void popIdx(){
            this->idx.pop_back();
            if(idx.size()>0) topIdx = idx[idx.size()-1];
            else topIdx = -1;
        }
        
        FreqIdx(int element, int frequency, vector<int> indexes){
            this->element = element;
            this->frequency = frequency;
            this->idx = indexes;
            if(idx.size()>0)topIdx = idx[idx.size()-1];
            else topIdx = -1;
        }
    };
    
    struct comparator{
        bool operator()(const FreqIdx& a, const FreqIdx& b){
            if(a.frequency==b.frequency){
                return a.topIdx < b.topIdx;
            }else return a.frequency < b.frequency;
        }
    };
    
    
    unordered_map<int, vector<int>> indexes;
    int idx = 0;
    priority_queue<FreqIdx, vector<FreqIdx>, comparator> pq;
    public:
    FreqStack() {
        
    }
    
    void push(int val) {
        this->indexes[val].push_back(idx);
        idx++;
        pq.push(FreqIdx(val, indexes[val].size(), indexes[val]));
        
//         for(auto a: indexes){
//             cout << a.first << ": {" ;
//             for(auto idx: a.second) cout << idx << ", ";
//             cout << "} \n";
//         }
        
//         cout << endl;
    }
    
    int pop() {
        FreqIdx f = pq.top();
        // cout << "pop called: " << f.element << endl;
        pq.pop();
        indexes[f.element].pop_back();
        // f.popIdx();
        // idx--;
        // pq.push(f);
        return f.element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */