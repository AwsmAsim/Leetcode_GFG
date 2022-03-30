class Solution {
    
    bool binarySearch2D(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = (m*n)-1, mid = (start + end)/2;
        while(start <= end){
            mid = (start + end)/2;
            // cout << "start: "<< start << " end: " << end << " mid: " << mid << endl;
            if(matrix[mid/n][mid%n] == target) break;
            if(matrix[mid/n][mid%n] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        if(matrix[mid/n][mid%n]==target) return true;
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch2D(matrix, target);   
    }
};