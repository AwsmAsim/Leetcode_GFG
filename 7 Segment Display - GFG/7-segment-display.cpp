// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) {
        // code here
        string ans = "";
        unordered_map<char, int> hashMap;
        hashMap['0'] = 6;
        hashMap['1'] = 2;
        hashMap['2'] = 5;
        hashMap['3'] = 5;
        hashMap['4'] = 4;
        hashMap['5'] = 5;
        hashMap['6'] = 6;
        hashMap['7'] = 3;
        hashMap['8'] = 7;
        hashMap['9'] = 5;
        S = S.substr(0, N);
        
        int count = 0, k;
        for(char ch: S)
            count += hashMap[ch];
        int n = S.size();
        char ch;
        while(n) {
            ch = '0';
            while(ch <= '8') {
                if(n == 1) {
                    if(hashMap[ch] == count) {
                        ans += ch;
                        --n;
                        count = 0;
                        break;
                    }
                }
                else {
                    k = count - hashMap[ch];
                    if(k / (n-1) > 1) {
                        ans += ch;
                        --n;
                        count -= hashMap[ch];
                        break;
                    }
                }
                ch++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends