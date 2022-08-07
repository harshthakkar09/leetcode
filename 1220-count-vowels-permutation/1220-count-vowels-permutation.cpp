#define mod 1000000007
typedef long long ll;
class Solution {
public:
    
    ll rec(int rem, int pre, vector<vector<ll>>& dp, map<int, vector<int>>& adj){
        if(rem == 0){
            return 1;
        }
        
        if(dp[rem][pre] != -1){
            return dp[rem][pre];
        }
        
        ll ans = 0;
        for(auto neg: adj[pre]){
            ans = (ans + rec(rem - 1, neg, dp, adj)) % mod;
        }
        return dp[rem][pre] = ans;
    }
    
    ll countVowelPermutation(int n) {
        vector<vector<ll>> dp(n, vector<ll> (5, - 1));
        map<int, vector<int>> adj;
        adj[0] = {1};
        adj[1] = {0, 2};
        adj[2] = {0, 1, 3, 4};
        adj[3] = {2, 4};
        adj[4] = {0};
        ll ans = 0;
        for(int i = 0; i < 5; i++){
            ans = (ans + rec(n - 1, i, dp, adj)) % mod;
        }
        return ans;
    }
};