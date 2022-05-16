class Solution {
public:
    
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(x<n && y<m && x>=0 && y>=0 && grid[x][y]==0 && !vis[x][y]){
            return true;
        }
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
        queue<pair<int,int>> q;
        if(grid[0][0]==0 && !vis[0][0]){
            q.push({0,0});
            vis[0][0]=true;
        }
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                pair<int,int> f=q.front();
                q.pop();
                int fx=f.first;
                int fy=f.second;
                if(fx==n-1 && fy==m-1){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    int nx=fx+dir[i][0];
                    int ny=fy+dir[i][1];
                    if(isValid(nx,ny,n,m,grid,vis)){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }    
            }
        }
        return -1;
    }
};