class Solution {
public:
    vector<int> v;
    
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> ans = v;
        int n = ans.size();
        for(int i = n - 1; i >= 0; i--){
            int random_index = rand() % (i+1);
            swap(ans[i], ans[random_index]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */