class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<pair<int,int>>> ltr(r,vector<pair<int,int>> (c,{0,0}));
        vector<vector<pair<int,int>>> rtl(r,vector<pair<int,int>> (c,{0,0}));
        vector<vector<pair<int,int>>> utd(r,vector<pair<int,int>> (c,{0,0}));
        vector<vector<pair<int,int>>> dtu(r,vector<pair<int,int>> (c,{0,0}));
        for(int i=0;i<r;i++){
            int num=grid[i][0];
            int x=0,y=0;
            while(num%2==0){
                x++;
                num/=2;
            }
            while(num%5==0){
                y++;
                num/=5;
            }
            ltr[i][0]={x,y};
            // cout<<"i "<<i<<" j "<<0<<" "<<ltr[i][0].first<<" "<<ltr[i][0].second<<"\n";
            for(int j=1;j<c;j++){
                // cout<<"i "<<i<<" j "<<j<<"\n";
                int num=grid[i][j];
                int x=0,y=0;
                while(num%2==0){
                    x++;
                    num/=2;
                }
                while(num%5==0){
                    y++;
                    num/=5;
                }
                // cout<<" x "<<x<<" y "<<y<<'\n';
                ltr[i][j]={x+ltr[i][j-1].first,y+ltr[i][j-1].second};
                // cout<<"i "<<i<<" j "<<j<<" "<<ltr[i][j].first<<" "<<ltr[i][j].second<<"\n";
            }
        }
        for(int i=0;i<r;i++){
            int num=grid[i][c-1];
            int x=0,y=0;
            while(num%2==0){
                x++;
                num/=2;
            }
            while(num%5==0){
                y++;
                num/=5;
            }
            rtl[i][c-1]={x,y};
            // cout<<"i "<<i<<" j "<<c-1<<" "<<rtl[i][c-1].first<<" "<<rtl[i][c-1].second<<"\n";
            for(int j=c-2;j>=0;j--){
                // cout<<"i "<<i<<" j "<<j<<"\n";
                int num=grid[i][j];
                int x=0,y=0;
                while(num%2==0){
                    x++;
                    num/=2;
                }
                while(num%5==0){
                    y++;
                    num/=5;
                }
                rtl[i][j]={x+rtl[i][j+1].first,y+rtl[i][j+1].second};
                // cout<<"i "<<i<<" j "<<j<<" "<<rtl[i][j].first<<" "<<rtl[i][j].second<<"\n";
            }
        }
        for(int i=0;i<c;i++){
            int num=grid[0][i];
            int x=0,y=0;
            while(num%2==0){
                x++;
                num/=2;
            }
            while(num%5==0){
                y++;
                num/=5;
            }
            utd[0][i]={x,y};
            // cout<<"j "<<0<<" i "<<i<<" "<<utd[0][i].first<<" "<<utd[0][i].second<<"\n";
            for(int j=1;j<r;j++){
                // cout<<"j "<<j<<" i "<<i<<"\n";
                int num=grid[j][i];
                int x=0,y=0;
                while(num%2==0){
                    x++;
                    num/=2;
                }
                while(num%5==0){
                    y++;
                    num/=5;
                }
                utd[j][i]={x+utd[j-1][i].first,y+utd[j-1][i].second};
                // cout<<"j "<<j<<" i "<<i<<" "<<utd[j][i].first<<" "<<utd[j][i].second<<"\n";
            }
        }
        for(int i=0;i<c;i++){
            int num=grid[r-1][i];
            // cout<<"num "<<num<<"\n";
            int x=0,y=0;
            while(num%2==0){
                x++;
                num/=2;
            }
            while(num%5==0){
                y++;
                num/=5;
            }
            dtu[r-1][i]={x,y};
            // cout<<"i "<<i<<" r-1 "<<r-1<<" "<<dtu[r-1][i].first<<" "<<dtu[r-1][i].second<<"\n";
            for(int j=r-2;j>=0;j--){
                int num=grid[j][i];
                int x=0,y=0;
                while(num%2==0){
                    x++;
                    num/=2;
                }
                while(num%5==0){
                    y++;
                    num/=5;
                }
                dtu[j][i]={x+dtu[j+1][i].first,y+dtu[j+1][i].second};
                 // cout<<"i "<<i<<" i "<<j<<" "<<dtu[j][i].first<<" "<<dtu[j][i].second<<"\n";
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int num=grid[i][j];
                int x=0,y=0;
                while(num%2==0){
                    x++;
                    num/=2;
                }
                while(num%5==0){
                    y++;
                    num/=5;
                }
                ans=max(ans,min(rtl[i][j].first+dtu[i][j].first-x,rtl[i][j].second+dtu[i][j].second-y));
                ans=max(ans,min(rtl[i][j].first+utd[i][j].first-x,rtl[i][j].second+utd[i][j].second-y));
                ans=max(ans,min(ltr[i][j].first+dtu[i][j].first-x,ltr[i][j].second+dtu[i][j].second-y));
                ans=max(ans,min(ltr[i][j].first+utd[i][j].first-x,ltr[i][j].second+utd[i][j].second-y));
            }
        }
        return ans;
    }
};