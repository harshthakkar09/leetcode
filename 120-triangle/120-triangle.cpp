class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=min(dp[j],dp[j+1])+arr[i][j];
            }
        }
        return dp[0];
    }
};