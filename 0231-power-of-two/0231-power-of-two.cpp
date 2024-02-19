typedef long long ll;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }
        return (((ll)n & ((ll)n - (ll)1)) == 0);
    }
};