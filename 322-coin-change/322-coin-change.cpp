class Solution {
public:
    
    int rec(int amount,vector<int>& dp,vector<int>& coins,int n){
        if(amount==0){
            return 0;
        }
        
        if(amount<0){
            return INT_MAX/2;
        }
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(1+rec(amount-coins[i],dp,coins,n),ans);
        }
        return dp[amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int n=coins.size();
        int ans=rec(amount,dp,coins,n);
        if(ans<=amount){
            return ans;
        }
        return -1;
    }
};