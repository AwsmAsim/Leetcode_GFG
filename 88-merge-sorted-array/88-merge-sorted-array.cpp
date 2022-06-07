class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0;
        vector<int> sortedArr;
        
        for(int i = m; i < nums1.size(); ++i){
            nums1[i] = INT_MAX;
        }
        
        while(ptr1 < m and ptr2 < n){
            if(nums1[ptr1] < nums2[ptr2]){
                sortedArr.push_back(nums1[ptr1]);
                ++ptr1;
            }else{
                sortedArr.push_back(nums2[ptr2]);
                ++ptr2;
            } 
        }
        
        while(ptr1<m){
            sortedArr.push_back(nums1[ptr1]);
            ++ptr1;
        }
        
        while(ptr2<n){
            sortedArr.push_back(nums2[ptr2]);
            ++ptr2;
        }
        
        for(int i = 0; i < nums1.size(); ++i){
            nums1[i] = sortedArr[i];
        }
        
    }
};