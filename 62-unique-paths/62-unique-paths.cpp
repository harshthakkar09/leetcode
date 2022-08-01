typedef long long ll;
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        ll up = m + n - 2, down = min(m, n) - 1, ans = 1;
        for(int i = 1; i <= down; i++){
            ans = (ans * up) / i;
            up--;
        }
        return (int)ans;
    }
};