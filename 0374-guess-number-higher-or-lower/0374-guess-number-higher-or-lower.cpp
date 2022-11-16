/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long start = 0, end = n, mid;
        int cGuess;
        
        while(start <= end){
            mid = (start + end) /2 ;
            // cout << mid << endl;
            cGuess = guess(mid);
            
            if(cGuess == 0) return (int) mid;
            else if(cGuess == -1) end = mid - 1;
            else start = mid + 1;
        }
        
        mid = (start + end) / 2;
        return (int)mid;
        
    }
};