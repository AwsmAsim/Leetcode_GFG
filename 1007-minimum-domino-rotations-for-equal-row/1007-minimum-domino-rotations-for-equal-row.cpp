class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> topFreq, bottomFreq;
        int flag = 0, maxElement, threshold, count = 0;
        if(tops.size()&1){
            threshold = 1 + (tops.size()/2);
        }else threshold = tops.size()/2;
        for(auto a: tops){
            topFreq[a]++;
        }
        for(auto a: bottoms){
            bottomFreq[a]++;
        }
        
        for(auto itr: topFreq){
            if(itr.second >= threshold){
                maxElement = itr.first;
                flag = 1;
            } 
        }
        
        for(auto itr: bottomFreq){
            // cout << itr.first <<":" << itr.second << endl;
            if(itr.second >= threshold){
                if(topFreq[maxElement] < bottomFreq[itr.first])maxElement = itr.first;
                flag = 1;
            } 
        }  
        
        // cout << "flag: " << flag << endl;
        
        if(flag){
            for(int i = 0; i < tops.size(); i++){
                if(tops[i]== maxElement || bottoms[i]==maxElement) count++;
            }
            // cout << "count: " << count << endl; 
            if(count == tops.size()){
                // cout << "maxElement: " << maxElement << "maximum: " << max(topFreq[maxElement], bottomFreq[maxElement]) << endl; 
                return tops.size() - max(topFreq[maxElement], bottomFreq[maxElement]);
            }else return -1;
            
        }else return -1;
        
    }
};