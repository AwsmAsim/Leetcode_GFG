class Solution {
    
    
    class ElementFreq{
        public:
        int element;
        int freq;
        ElementFreq(int element, int freq){
            this->element = element;
            this->freq = freq;
        }
    };
    
    struct comparator{
        bool operator()(const ElementFreq& a, const ElementFreq& b){
            return a.freq > b.freq;
        }   
    };
    
    void printPQ(priority_queue<ElementFreq, vector<ElementFreq>, comparator> pq){
        priority_queue<ElementFreq, vector<ElementFreq>, comparator> pq1 = pq;
        cout << "priority queue: ";
        while(pq1.size()){
            cout << pq1.top().element << ":" << pq1.top().freq << " " << endl;
            pq1.pop();
        }
        cout << endl;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<ElementFreq, vector<ElementFreq>, comparator> pq;
        unordered_map<int, int> hMap;
        
        vector<int> answer;
        
        for(int i = 0; i < nums.size(); i++) hMap[nums[i]]++;
        
        for(auto it: hMap){
            if(k){
                pq.push(ElementFreq(it.first, it.second));
                --k;
                // printPQ(pq);
            }else{
                if(it.second>pq.top().freq){
                    pq.pop();
                    pq.push(ElementFreq(it.first, it.second));
                    // printPQ(pq);
                }
            }
        }
        
        while(!pq.empty()){
            answer.push_back(pq.top().element);
            pq.pop();
        }
        
        return answer;
    }
};