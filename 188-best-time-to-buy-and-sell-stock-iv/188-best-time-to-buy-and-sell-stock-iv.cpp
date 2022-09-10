class Solution {
public:
    int rec(vector<int>& prices, int n, int i, int purchased, int k, unordered_map<string, int>& dp){
        
        if(k == 0 || i == n){
            return 0;
        }
        
        string key = to_string(i)+" "+to_string(purchased)+" "+to_string(k);
        
        if(dp.find(key) != dp.end()){
            return dp[key];
        }
        
        int ans = INT_MIN;
        if(purchased){
            ans = max(ans, prices[i] + rec(prices, n, i + 1, 0, k - 1, dp));
            ans = max(ans, rec(prices, n, i + 1, 1, k, dp));
        }
        else{
            ans = max(ans, rec(prices, n, i + 1, 0, k, dp));
            ans = max(ans, -prices[i] + rec(prices, n, i + 1, 1, k, dp));
        }
        return dp[key] = ans;
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        unordered_map<string, int> dp;
        return rec(prices, n, 0, 0, k, dp);
    }
};