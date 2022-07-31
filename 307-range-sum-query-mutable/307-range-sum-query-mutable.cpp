class NumArray {
    
    vector<int> arr;
    int sum = 0;
    
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int a: nums) sum += a;
        // cout << "intial sum: " << sum << endl;
    }
    
    void update(int index, int val) {
        sum -= arr[index];
        arr[index] = val;
        sum += val;
        
        // cout << sum << endl;
        
    }
    
    int sumRange(int left, int right) {
        int res = sum;
        for(int i = 0; i < left; i++){
            res -= arr[i];
        }
        for(int i = right + 1; i < arr.size(); i++)
            res -= arr[i];
        
        // cout << "final rs: " << res << endl;
        
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */