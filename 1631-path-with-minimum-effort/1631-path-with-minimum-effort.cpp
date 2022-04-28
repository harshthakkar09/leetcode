class Solution {
public:
    
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    bool isPossible(int x,int y,int n,int m,int mid,vector<vector<int>>& h,vector<vector<bool>>& vis){
        // cout<<"x "<<x<<" y "<<y<<" mid "<<mid<<"\n"; 
        if(x==n-1 && y==m-1){
            return true;
        }
        vis[x][y]=true;
        bool ans=false;
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(isValid(nx,ny,n,m) && !vis[nx][ny] && abs(h[x][y]-h[nx][ny])<=mid){
                ans=ans||isPossible(nx,ny,n,m,mid,h,vis);
            }
        }
        return ans;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0,r=INT_MAX,ans,n=heights.size(),m=heights[0].size();
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>> vis(n,vector<bool> (m,false));
            // cout<<"l "<<l<<" r "<<r<<" mid "<<mid<<"\n";
            if(isPossible(0,0,n,m,mid,heights,vis)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};