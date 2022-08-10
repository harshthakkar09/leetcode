class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            int cur = s[i] - 'a';
            for(int j = cur; j < 26 && j <= cur + k; j++){
                if(j == cur && dp[j] == 0){
                    dp[j] = 1;
                    ans = max(dp[j], ans);
                    continue;
                }
                dp[cur] = max(dp[cur] , dp[j] + 1);
            }
            for(int j = cur - 1; j >= 0 && j >= cur - k; j--){
                dp[cur] = max(dp[cur] , dp[j] + 1);
            }
            ans = max(ans, dp[cur]);
        }
        return ans;
    }
};