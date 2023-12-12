class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return ans;
    }
};