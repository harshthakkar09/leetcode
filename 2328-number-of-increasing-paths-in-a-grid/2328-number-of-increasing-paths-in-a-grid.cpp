# define mod 1000000007
class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid, int n, int m, int parent){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= parent){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = dfs(i + 1, j, dp, grid, n, m, grid[i][j]);
        int up = dfs(i - 1, j, dp, grid, n, m, grid[i][j]);
        int right = dfs(i, j + 1, dp, grid, n, m, grid[i][j]);
        int left = dfs(i, j - 1, dp, grid, n, m, grid[i][j]);
    
        return dp[i][j] = (up % mod + down % mod + right % mod + left % mod + 1) % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    dfs(i, j, dp, grid, n, m, -1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};