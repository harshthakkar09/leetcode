class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        double log_base_4 = log(n) / log(4);
        return log_base_4 == int(log_base_4);
    }
};
