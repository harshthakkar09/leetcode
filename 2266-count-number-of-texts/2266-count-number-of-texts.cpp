#define mod 1000000007
class Solution {
public:
    
    int countTexts(string keys) {
        int n=keys.size();
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            char ch=keys[i-1];
            if(i>=2 && ch==keys[i-2]){
                dp[i]=(dp[i]+dp[i-2])%mod;
            }
            else{
                continue;
            }
            if(i>=3 && ch==keys[i-3]){
                dp[i]=(dp[i]+dp[i-3])%mod;
            }
            else{
                continue;
            }
            if((ch=='7' || ch=='9') && i>=4 && ch==keys[i-4]){
                dp[i]=(dp[i]+dp[i-4])%mod;
            }
        }
        return dp[n];
    }
};