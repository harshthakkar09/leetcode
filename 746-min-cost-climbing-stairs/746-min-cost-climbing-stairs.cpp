class Solution {
public:
    
    int rec(int i,vector<int>& cost,vector<int>& dp){
        if(i>=cost.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int op1=rec(i+1,cost,dp);
        int op2=rec(i+2,cost,dp);
        
        return dp[i]=cost[i]+min(op1,op2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(rec(0,cost,dp),rec(1,cost,dp));
    }
};