class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tries = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(tries + 1));
    }
};