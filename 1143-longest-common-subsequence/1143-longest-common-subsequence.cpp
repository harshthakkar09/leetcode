class Solution {
public:
    
    int helper(int i, int j, string& a, string& b, int n, int m, vector<vector<int>>& dp) {
    if (i == n || j == m) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        return dp[i][j] = 1 + helper(i + 1, j + 1, a, b, n, m, dp);
    } else {
        return dp[i][j] = max(helper(i + 1, j, a, b, n, m, dp), helper(i, j + 1, a, b, n, m, dp));
    }
}

    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(0, 0, text1, text2, n, m, dp);
    }
};