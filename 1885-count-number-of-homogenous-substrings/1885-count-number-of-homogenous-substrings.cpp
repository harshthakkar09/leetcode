#define mod 1000000007
typedef long long ll;
class Solution {
public:
    int countHomogenous(string s) {
        int i = 0, j = 0, n = s.size();
        ll ans = 0;
        while(j < n){
            // cout<<"j: "<<j<<" i: "<<i<<"\n";
            while(s[i] == s[j]){
                // cout<<"gaya"<<"\n";
                j++;
            }
            ll len = (ll)j - (ll)i;
            // cout<<"len: "<<len<<"\n";
            // cout<<"j: "<<j<<" i: "<<i<<"\n";
            ll tans = ((len) * (len + 1)) % mod;
            tans /= 2;
            ans = (ans + tans) % mod;
            i = j;
        }
        return ans;
    }
};