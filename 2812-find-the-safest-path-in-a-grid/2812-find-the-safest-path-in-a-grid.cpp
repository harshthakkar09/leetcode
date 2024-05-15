class Solution {
public:
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool isValid(int x, int y, vector<vector<bool>>& vis){
        int n = vis.size();
        return (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]);
    }
    
    bool isSafe(int target, vector<vector<int>>& distance){
        if(distance[0][0] < target){
            return false;
        }
        
        int n = distance.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        vis[0][0] = true;
        q.push({0, 0});
        while(!q.empty()){
            int frontX = q.front().first, frontY = q.front().second;
            if(frontX == n - 1 && frontY == n - 1){
                return true;
            }
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = frontX + dir[i][0], newY = frontY + dir[i][1];
                if(isValid(newX, newY, vis) && distance[newX][newY] >= target && !vis[newX][newY]){
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), len = 0, left = 0, right, ans;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<vector<int>> distance(n, vector<int> (n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        // cout<<"size of starting queue "<<q.size()<<"\n";
        while(!q.empty()){
            int sz = q.size();
            // cout<<"sz: "<<sz<<"\n";
            while(sz--){
                int frontX = q.front().first, frontY = q.front().second;
                q.pop();
                distance[frontX][frontY] = len;
                for(int i = 0; i < 4; i++){
                    int newX = frontX + dir[i][0], newY = frontY + dir[i][1];
                    if(isValid(newX, newY, vis)){
                        q.push({newX, newY});
                        vis[newX][newY] = true;
                    }
                }
            }
            len++;
        }
        // cout<<"done BFS"<<"\n";
        right = len;
        while(left <= right){
            int mid = (left + right) / 2;
            if(isSafe(mid, distance)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        // cout<<"done BS"<<"\n";
        return ans;
    }
};