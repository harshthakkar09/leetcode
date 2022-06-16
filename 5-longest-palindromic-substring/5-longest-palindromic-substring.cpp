class Solution {
public:
    
    bool rec(int l,int r,vector<vector<int>>& dp,vector<int>& ans,string& s){
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        
        if(l>=r){
            return true;
        }
        
        bool possible=false;
        if(s[l]==s[r]){
            possible=rec(l+1,r-1,dp,ans,s);
        }
        
        rec(l+1,r,dp,ans,s);
        rec(l,r-1,dp,ans,s);
        
        if(possible && (r-l+1)>ans[2]){
            ans={l,r,r-l+1};
        }
        
        return dp[l][r]=possible;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> ans={0,0,1};
        rec(0,n-1,dp,ans,s);
        return s.substr(ans[0],ans[2]);
    }
};