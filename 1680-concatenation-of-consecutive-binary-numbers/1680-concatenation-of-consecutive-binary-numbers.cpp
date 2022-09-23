typedef long long ll;
#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0;
        int i = 1;
        while(i <= n){
            ans = ((ans << (1 + int(log2(i)))) % mod + i) % mod;
            i++;
        }
        return ans;
    }
};