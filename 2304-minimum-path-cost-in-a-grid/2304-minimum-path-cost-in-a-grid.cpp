class Solution {
public:
    int rec(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& cost,vector<vector<int>>& dp){
     
        if(i==n-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int temp_ans=INT_MAX,cur=grid[i][j];
        for(int h=0;h<m;h++){
            temp_ans=min(temp_ans,cur+cost[cur][h]+rec(i+1,h,n,m,grid,cost,dp));
        }
        return dp[i][j]=temp_ans;
    }
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int n=grid.size(),m=grid[0].size(),ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<m;i++){
            ans=min(ans,rec(0,i,n,m,grid,cost,dp));
        }
        return ans;
    }
};