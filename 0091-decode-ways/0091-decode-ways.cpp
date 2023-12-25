class Solution {
public:
    
    int helper(int i, int n, vector<int>& dp, string& s){
        // cout<<"i: "<<i<<"\n";
        if(i == n){
            return 1;
        }
        
        if(s[i] == '0'){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int ans1 = helper(i + 1, n, dp, s);
        int ans2 = 0;
        if(stoi(s.substr(i, 2)) >= 10 && stoi(s.substr(i, 2)) <= 26){
            ans2 = helper(i + 2, n, dp, s);
        }
        return dp[i] = ans1 + ans2;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return helper(0, n, dp, s);
    }
};