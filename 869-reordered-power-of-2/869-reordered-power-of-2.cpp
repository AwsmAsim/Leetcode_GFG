class Solution {
    

    map<int, pair<int,int> > digitPowerRange = {
        {1, {0, 3}}, {2, {4,6}}, {3, {7,9}}, {4, {10,13}},
        {5, {14,16}}, {6,{17,19}}, {7,{20,23}}, {8, {24,26}}, {9, {27,29}}
    }; // {power of two, {first power with this number of digits, last power with this no of digits}}
    
    vector<map<int, int>> powerOfTwoDigitsMap;
    
    map<int, int> generateMap(int n){
        // Generate map for number n.
        map<int, int> m1;
        while(n){
            m1[n%10]++;
            n/=10;
        }
        return m1;
    }
    
    void generateNumbers(int n){
        // Generate numbers that have n number of digits.
        pair<int, int> range = digitPowerRange[n];
        int startRange = range.first, endRange = range.second;
        
        for(int i = startRange; i <= endRange; i++){
            powerOfTwoDigitsMap.push_back(generateMap((int)pow(2, i)));
        }
    }
    
    int countNumberOfDigits(int n){
        int count = 0;
        while(n){
            n/=10;
            ++count;
        }
        // cout << "It contains " << count << " digits" << endl;
        return count;
    }
    
    bool checkMapsEqual(map<int, int> m1, map<int, int> m2){
        return m1 == m2;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        
        generateNumbers(countNumberOfDigits(n));
        map<int, int> m1 = generateMap(n);
        for(int i = 0; i < powerOfTwoDigitsMap.size(); i++){
            if(checkMapsEqual(m1, powerOfTwoDigitsMap[i])) return true;
        }
        return false;
    }
};