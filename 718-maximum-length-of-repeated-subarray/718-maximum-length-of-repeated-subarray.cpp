class Solution {
public:
    int ans = 0;
    
    int rec(vector<int>& nums1, vector<int>& nums2, int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i == n || j == m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int tans = 0;
        if(nums1[i] == nums2[j]){
            tans = 1 + rec(nums1, nums2, n, m, i + 1, j + 1, dp);
        }
        
        rec(nums1, nums2, n, m, i + 1, j, dp);
        rec(nums1, nums2, n, m, i, j + 1, dp);
        
        ans = max(ans, tans);
        return dp[i][j] = tans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        rec(nums1, nums2, n, m, 0, 0, dp);
        return ans;
    }
};