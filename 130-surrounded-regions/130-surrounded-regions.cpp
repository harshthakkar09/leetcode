class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
    
    bool isValid(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    void bfs(vector<vector<char>>& b,int n,int m,int x,int y){
        queue<pair<int,int>> q;
        b[x][y]='Y';
        q.push({x,y});
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            int cx=f.first,cy=f.second;
            for(int i=0;i<4;i++){
                int nx=cx+dir[i][0];
                int ny=cy+dir[i][1];
                if(isValid(nx,ny,n,m) && b[nx][ny]=='O'){
                     b[nx][ny]='Y';
                     q.push({nx,ny});
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                bfs(board,n,m,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                bfs(board,n,m,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                bfs(board,n,m,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                bfs(board,n,m,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
        }
    }
};