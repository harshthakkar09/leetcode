class Solution {
public:
    string a,b,s;
    int as,bs,ss;

    int rec(int i,int j,int k,vector<vector<int>>& dp){
        if(j==bs && k==ss){
            return 1;
        }

        if(i==as && k==ss){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool ans1,ans2;
        if(i<as && a[i]==s[k]){
            ans1=rec(i+1,j,k+1,dp);
        }
        if(j<bs && b[j]==s[k]){
            ans2=rec(i,j+1,k+1,dp);
        }
        return dp[i][j]=ans1|ans2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        a=s1;
        b=s2;
        s=s3;
        as=a.size();
        bs=b.size();
        ss=s.size();
        if(as+bs!=ss){
            return false;
        }
        vector<vector<int>> dp(205, vector<int> (205,-1));
        if(rec(0,0,0,dp)){
            return true;
        }
        return false;                
    }
};