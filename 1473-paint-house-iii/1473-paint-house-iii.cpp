class Solution {
public:
    
    int rec(int ind, int colour_index, int strick, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, vector<vector<vector<int>>>& dp){
        
        if(ind==m){
            if(strick==target){
                return 0;
            }
            else{
                return INT_MAX/2;
            }
        }
        
        if(ind > m){
            return INT_MAX/2;
        }
        
        if(strick > target){
            return INT_MAX/2;
        }
        
        if(dp[ind][colour_index][strick] != -1){
            return dp[ind][colour_index][strick];
        }
        
        int ans=INT_MAX/2;
        if(houses[ind] != 0){
            if(houses[ind] == colour_index){
                ans = min(ans, rec(ind+1, houses[ind], strick, houses, cost, m, n, target, dp));
            }
            else{
                ans = min(ans, rec(ind+1, houses[ind], strick + 1, houses, cost, m, n, target, dp));
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if((i+1) == colour_index){
                    ans = min(ans, cost[ind][i] + rec(ind+1, i+1, strick, houses, cost, m, n, target, dp));
                }
                else{
                    ans = min(ans, cost[ind][i] + rec(ind+1, i+1, strick + 1, houses, cost, m, n, target, dp));
                }
            }
        }
        return dp[ind][colour_index][strick] = ans;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(105, vector<vector<int>> (25, vector<int> (105,-1)));
        int ans=rec(0, 0, 0, houses, cost, m, n, target, dp);
        if(ans==INT_MAX/2){
            return -1;
        }
        else{
            return ans;
        }
    }
};