typedef long long ll;
class Solution {
public:
    bool isPalindrome(ll x) {
        if(x<0){
            return false;
        }
        ll temp=x,cur=0;
        while(x){
            int r=(x%10);
            cur=(cur*10)+r;
            x/=10;
        }
        return cur==temp;
    }
};