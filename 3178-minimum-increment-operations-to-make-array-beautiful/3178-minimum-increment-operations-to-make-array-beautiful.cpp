typedef long long ll;
class Solution {
public:

    ll helper(vector<int>& nums, int n, int k, int ind, vector<ll>& dp){
        if(ind >= n - 2){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        ll op1 = max(0, k - nums[ind]) + helper(nums, n, k, ind + 1, dp);
        ll op2 = max(0, k - nums[ind + 1]) + helper(nums, n, k, ind + 2, dp);
        ll op3 = max(0, k - nums[ind + 2]) + helper(nums, n, k, ind + 3, dp);

        return dp[ind] = min(op1, min(op2, op3));
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(n, -1);
        return helper(nums, n, k, 0, dp);
    }
};