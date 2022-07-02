class Solution {
public:
    bool solve(int i,int last,vector<int> &stones,map<int,int> &m, vector<vector<int>> &dp){
        if(i==stones.size()-1){
            return true;    
        } 
        if(dp[i][last]!=-1){
            return dp[i][last];
        } 
        int ans=false;
        for(int di=-1;di<=1;di++){
            if(m[stones[i]+(last+di)] && last+di>0 && solve(m[stones[i]+(last+di)],last+di,stones,m,dp)){
                return dp[i][last]= true;
            }
        }
        return dp[i][last]=false;
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        } 
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,stones,m,dp);
    }
};