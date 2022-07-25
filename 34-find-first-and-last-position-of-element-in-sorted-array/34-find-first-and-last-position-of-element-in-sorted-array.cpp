class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb >= 0 && lb < n && nums[lb] == target){
            int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(ub > 1 && nums[ub - 1] == target){
                return {lb, ub - 1};
            }
            else{
                return {lb, lb};
            }
        }
        else{
            return {-1, -1};
        }
    }
};