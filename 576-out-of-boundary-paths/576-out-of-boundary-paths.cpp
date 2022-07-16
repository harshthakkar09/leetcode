#define mod 1000000007

typedef long long ll;

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    ll rec(int row, int col, int move, int x, int y, vector<vector<vector<ll>>>& dp){
        if(move < 0){
            return 0;
        }
        
        if(x == row || y == col || x < 0 || y < 0){
            return 1;
        }
        
        if(dp[x][y][move] != -1){
            return dp[x][y][move];
        }
        
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            ans = (ans + rec(row, col, move - 1, nx, ny, dp)) % mod;
        }
        return dp[x][y][move] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> dp(51, vector<vector<ll>> (51, vector<ll> (51, -1)));
        return (int)rec(m, n, maxMove, startRow, startColumn, dp);
    }
};