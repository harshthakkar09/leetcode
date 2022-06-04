class Solution {
public:
    
    bool isPossible(int x,int y,vector<int>& row,vector<int>& col,vector<int>& d1,vector<int>& d2,int n){
        if(row[x]!=0){
            return false;
        }
        if(col[y]!=0){
            return false;
        }
        if(d1[x+y]!=0){
            return false;
        }
        if(d2[x-y+n-1]!=0){
            return false;
        }
        return true;
    }
    
    void rec(int col,vector<string>& cur,vector<vector<string>>& ans,int n,vector<int>& row_track,vector<int>& col_track,vector<int>& diag1,vector<int>& diag2){
        
        if(col==n){
            ans.push_back(cur);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(cur[col][i]=='.'){
                if(isPossible(i,col,row_track,col_track,diag1,diag2,n)){
                    cur[col][i]='Q';
                    row_track[i]=1;
                    col_track[col]=1;
                    diag1[i+col]=1;
                    diag2[i-col+n-1]=1;
                    rec(col+1,cur,ans,n,row_track,col_track,diag1,diag2);
                    cur[col][i]='.';
                    row_track[i]=0;
                    col_track[col]=0;
                    diag1[i+col]=0;
                    diag2[i-col+n-1]=0;
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tans(n);
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            tans[i]=s;
        }
        vector<int> row_track(n);
        vector<int> col_track(n);
        vector<int> diag1(2*n-1);
        vector<int> diag2(2*n-1);
        rec(0,tans,ans,n,row_track,col_track,diag1,diag2);
        return ans;
    }
};