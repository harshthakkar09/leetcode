typedef long long ll;
#define mod 1000000007
class Solution {
public:
    
    ll helper(int rolls, int sum, int target, int n, int k, vector<vector<ll>>& dp){
        if(rolls == n){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(sum >= target){
            return 0;
        }
        
        if(dp[rolls][sum] != -1){
            return dp[rolls][sum];
        }
        
        ll ans = 0;
        for(int i = 1; i <= k; i++){
            ans = (ans + helper(rolls + 1, sum + i, target, n, k, dp)) % mod;
        }
        return dp[rolls][sum] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(31,  vector<ll> (1001, -1));
        return helper(0, 0, target, n, k, dp);
    }
};