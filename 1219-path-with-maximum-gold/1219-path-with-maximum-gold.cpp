class Solution {
public:
    
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int helper(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        
        
        int ans = 0, orgVal = grid[i][j];
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k][0], nj = j + dir[k][1];
             grid[i][j] = 0;
            ans = max(ans, orgVal + helper(ni, nj, n, m, grid));
            grid[i][j] = orgVal;
        }
        
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    ans = max(ans, helper(i, j, n, m, grid));
                }
            }
        }
        return ans;
    }
};