class Solution {
public:
    
    int dp[601][101][101];
    
    pair<int,int> calculate(string& s){
        int n=s.size();
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                x++;
            }
            else{
                y++;
            }
        }
        return {x,y};
    }
    
    int rec(vector<string>& v,int ind,int m,int n,int s){         
        if(ind>=s){
            return 0;
        }
        
        if(dp[ind][m][n]!=-1){
            return dp[ind][m][n];
        }
        
        pair<int,int> p=calculate(v[ind]);
        int x=p.first;
        int y=p.second;
        int ans1=rec(v,ind+1,m,n,s);
        int ans2=0;
        if(m>=x && n>=y){
            ans2=1+rec(v,ind+1,m-x,n-y,s);
        }
        return dp[ind][m][n]=max(ans1,ans2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        memset(dp,-1,sizeof(dp));
        return rec(strs,0,m,n,s);
    }
};