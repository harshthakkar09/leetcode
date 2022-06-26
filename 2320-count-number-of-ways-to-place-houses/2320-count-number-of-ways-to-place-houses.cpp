#define mod 1000000007
class Solution {
public:
    int countHousePlacements(int n) {
        if(n==1){
            return 4;
        }
        if(n==2){
            return 9;
        }
        int a=2,b=3,c;
        for(int i=3;i<=n;i++){
            c=(a+b)%mod;
            a=b;
            b=c;
        }
        return (1LL*c*c)%mod;
    }
};