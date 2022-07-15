class Solution {
public:
    int ans = 0;
    
    bool isValid(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y];
    }
    
    void bfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m){
        int count = 1;
        vis[x][y] = true;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(isValid(nx, ny, vis, grid, n, m)){
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }       
        }
        ans = max(ans, count);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]){
                    bfs(i, j, vis, grid, n, m);
                }
            }
        }
        return ans;
    }
};