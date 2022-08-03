class MyCalendar {
    
    vector<vector<int>> bookedRecords;
    
public:
    
    bool intersection(vector<int>& existing, vector<int> candidate){
        
        int start = 0, end = 1;
        
        // occurs before
        if(existing[start] >= candidate[end]) return false;
        
        // occurs later
        if(existing[end] <= candidate[start]) return false;
        
        return true;
    }
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(vector<int> v: bookedRecords){
            
            
            if(max(start, v[0]) < min(end, v[1])){
                return false;
            }
            
        }
        bookedRecords.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */