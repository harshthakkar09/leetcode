class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);
        while(l<=r){
            if(pow(l, 2) + pow(r, 2) == c){
                return true;
            }
            else if(pow(l, 2) + pow(r, 2) > c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};