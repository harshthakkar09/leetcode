typedef long long ll;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n+1);
        dp[1]=1;
        ll ans=0, mod = (ll)1e9 + 7, current_count=0;
        for(int i = 2; i <= n; i++){
            if(i-delay >= 1){
                current_count = (current_count + dp[i-delay]) % mod;
            }
            if(i-forget >= 1){
                current_count = (current_count - dp[i-forget] + mod) % mod;
            }
            dp[i] = current_count;
        }
        for(int i = n - forget + 1; i <= n; i++){
            ans = (ans + dp[i]) % mod;
        }
        return (int) ans;
    }
};