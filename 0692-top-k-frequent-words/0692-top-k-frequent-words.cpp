class Solution {
public:
    
    class Comparator{
      public:
        bool operator()(const pair<int, string>& p1, const pair<int, string>& p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;
        
        for(string word: words){
            ++freq[word];
        }
        
        priority_queue<pair<int, string>, vector< pair<int, string> >, Comparator> pq;
        
        for(pair<string, int> p: freq){
            if(pq.size() < k){
                pq.push(pair<int, string>(p.second, p.first));
            }else{
                if(pq.top().first < p.second){
                    pq.pop();
                    pq.push(pair<int, string>(p.second, p.first));
                }else if(pq.top().first == p.second and pq.top().second > p.first){
                    pq.pop();
                    pq.push(pair<int, string>(p.second, p.first));
                }
            }
        }
        
        vector<string> answer;
        
        while((!pq.empty())){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};