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
            for(int j=1;j<c;j++){
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
                ltr[i][j]={x+ltr[i][j-1].first,y+ltr[i][j-1].second};
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
            for(int j=c-2;j>=0;j--){
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
            for(int j=1;j<r;j++){
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
            }
        }
        for(int i=0;i<c;i++){
            int num=grid[r-1][i];
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