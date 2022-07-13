class Solution {
public:
    
    int rec(int i, int pre1, int pre2, int n, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int swapped){
        if(i == n){
            return 0;
        }
        if(dp[i][swapped] != -1){
            return dp[i][swapped];
        }
        int ans = INT_MAX;
        if(nums1[i] > pre1 && nums2[i] > pre2){
            ans = min(ans, rec(i + 1, nums1[i], nums2[i], n, nums1, nums2, dp, 0));
        }
        swap(nums1[i] , nums2[i]);
        if(nums1[i] > pre1 && nums2[i] > pre2){
            ans = min(ans, 1 + rec(i + 1, nums1[i], nums2[i], n, nums1, nums2, dp, 1));
        }
        swap(nums1[i], nums2[i]);
        return dp[i][swapped] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return rec(0, -1, -1, n, nums1, nums2, dp, 0);
    }
};