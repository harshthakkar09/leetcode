class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        int gs=g.size();
        int ws=w.size();
        vector<vector<int>> v(m,vector<int> (n,0));
        for(int i=0;i<gs;i++){
            int x=g[i][0],y=g[i][1];
            v[x][y]=2;
        }
        for(int i=0;i<ws;i++){
            int x=w[i][0],y=w[i][1];
            v[x][y]=-2;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==2){
                    // cout<<"i "<<i<<" j "<<j<<"\n";
                    // going up
                    for(int k=i-1;k>=0;k--){
                        if(v[k][j]==2 || v[k][j]==-2){
                            break;
                        }
                        v[k][j]=1;    
                    }
                    // going down
                    for(int k=i+1;k<m;k++){
                        if(v[k][j]==2 || v[k][j]==-2){
                            break;
                        }
                        v[k][j]=1;    
                    }
                    // going left
                    for(int k=j-1;k>=0;k--){
                        if(v[i][k]==2 || v[i][k]==-2){
                            break;
                        }
                        v[i][k]=1;
                    }
                    // going right
                    for(int k=j+1;k<n;k++){
                        if(v[i][k]==2 || v[i][k]==-2){
                            break;
                        }
                        v[i][k]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};