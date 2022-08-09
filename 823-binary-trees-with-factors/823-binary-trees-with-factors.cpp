typedef long long ll;
#define mod 1000000007
class Solution {
public:
    ll numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_map<ll, ll> dp;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            dp[arr[i]] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] ==  0){
                    ll fact1 = arr[i] / arr[j], fact2 = arr[j], freq1 = dp[fact1], freq2 = dp[fact2];
                    dp[arr[i]] += (freq1 * freq2) % mod;
                }
            }
        }
        ll ans = 0;
        for(auto it: dp){
            ans = (ans + it.second) % mod;
        }
        return ans;
    }
};