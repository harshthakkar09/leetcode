class Solution {
public:
    
    int rec(int pre,int len,int n,vector<vector<int>>& dp){
        if(dp[pre][len]!=-1){
            return dp[pre][len];
        }
        
        if(len==n){
            return dp[pre][len]=1;
        }
        
        int ans=0;
        
        for(int i=pre;i<=5;i++){
            ans+=rec(i,len+1,n,dp);
        }
        
        return dp[pre][len]=ans;
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6,vector<int> (55,-1));
        return rec(1,0,n,dp);
    }
};