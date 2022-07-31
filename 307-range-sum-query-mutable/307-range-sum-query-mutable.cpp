class NumArray {
public:
    int n;
    int st[1000000];
    int nums[40000];
    
    int getSum(int cur_ind, int sl,int sr, int l, int r){
        if(l <= sl && sr <= r){
            return st[cur_ind];
        }
        if(r < sl || l > sr){
            return 0;
        }
        int mid = (sl +sr ) / 2;
        return getSum((2 * cur_ind) + 1, sl, mid, l, r)+ getSum((2 * cur_ind) + 2,mid + 1, sr, l, r);
    }
    
    int constructTree(int cur_ind, int l, int r){
        if(l == r){
            st[cur_ind] = nums[l];
            return nums[l];
        }
        int mid= (l+r) / 2;
        st[cur_ind] = constructTree((2 * cur_ind + 1), l, mid) + constructTree(( 2* cur_ind + 2), mid + 1, r);
        return st[cur_ind];
    }
    
    void updateTree(int cur_ind, int l, int r, int pos, int diff){
        if(pos < l || pos > r){
            return;
        }
        st[cur_ind] += diff;
        if(l != r){
            int mid = (l + r) / 2;
            updateTree((2 * cur_ind) + 1, l, mid, pos, diff);
            updateTree((2 * cur_ind) + 2, mid + 1, r, pos, diff);    
        }
    }
    
    NumArray(vector<int>& nums_init) {
        for(int i = 0; i < 1000000; i++){
            st[i] = 0;
        }
        n = nums_init.size();
        for(int i = 0; i < n; i++){
            nums[i] = nums_init[i];
        }
        int l = 0, r = n - 1;
        st[0] = constructTree(0, l, r);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateTree(0, 0, n - 1, index, diff);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */