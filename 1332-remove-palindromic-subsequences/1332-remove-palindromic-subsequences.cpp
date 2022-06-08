class Solution {
public:
    int removePalindromeSub(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        if(s==str){
            return 1;
        }
        return 2;
    }
};