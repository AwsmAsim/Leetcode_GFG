class MyCalendarThree {
    
public:
    
    class Comparator{
        public:
        bool operator()(const int& num1, const int& num2){
            return num1 > num2;
        }
    };
    
    vector<pair<int, int>> intervals;
    
    MyCalendarThree() {
        
    }
    
    int meetingRooms(int start, int end){
        intervals.push_back( pair<int, int>(start, end) );
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, Comparator> pq;
        pq.push(intervals[0].second);
        
        for(int i = 1; i < intervals.size(); i++){
            int minEndPoint = pq.top();
            // cout << minEndPoint << endl;
            if(intervals[i].first < minEndPoint){
                // cout << "\t" << intervals[i].first << endl;
                pq.push(intervals[i].second);
            }else{
                pq.pop();
                pq.push(intervals[i].second);
            }
        }
        
        // cout << endl;
        return pq.size();
    }
    
    int book(int start, int end) {
        return meetingRooms(start, end);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */