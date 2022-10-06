class TimeMap {
    
    // map will be of type [key][timeStamp]

    map<string, map<int, string>> hMap; // hMap["foo"][1] = "bar"
    unordered_map<string, int> highestTs;
    unordered_map<string, int> lowestTs;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hMap[key][timestamp] = value;
        highestTs[key] = max((int)highestTs[key], timestamp);
        if(lowestTs.find(key) == lowestTs.end()) 
        {
            lowestTs[key] = timestamp;
            return;
        }
        lowestTs[key] = min((int)lowestTs[key], timestamp);
    }
    
    string get(string key, int timestamp) {
        
        // if the key is not present than simply ignore it
        if(hMap.find(key) == hMap.end()) return "";
        
        // If it is less than the lowest ts of that key, theres nothing to return 
        if(timestamp < lowestTs[key]) return "";
        
        // If the element is present return it.
        if(hMap[key].find(timestamp) != hMap[key].end()) return hMap[key][timestamp];
        
        // In case its not present check the highest timestamp value present.
        // This is important because we need to be away from the bad alloc() error.
        int ts_prev = highestTs[key];
        
        // In case the highest is less more than the asked timestamp.
        // We can consider it and so we have to take the prev of its lowerbound.
        if(ts_prev > timestamp) ts_prev = (*prev(hMap[key].lower_bound(timestamp))).first;
        
        // cout << "ts_prev: " << ts_prev << endl;
        return hMap[key][ts_prev];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */