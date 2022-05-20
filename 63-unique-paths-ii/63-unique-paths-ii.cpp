class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1}};
    
    bool isValid(int x,int y,int n,int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int rec(int i,int j,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i>=n || j>=m){
            return 0;
        }
        
        if(i==n-1 && j==m-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int cur_ans=0;
        for(int k=0;k<2;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(isValid(ni,nj,n,m) && grid[ni][nj]==0){
                cur_ans+=rec(ni,nj,n,m,dp,grid);    
            }
        }
        return dp[i][j]=cur_ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return rec(0,0,n,m,dp,obstacleGrid);
    }
};