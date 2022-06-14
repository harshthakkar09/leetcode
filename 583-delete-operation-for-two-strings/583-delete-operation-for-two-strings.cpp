class Solution {
public:
    
    int rec(int i,int j,int n,int m,vector<vector<int>>& dp,string& s1,string& s2){
        if(i==n && j==m){
            return 0;
        }
        
        if(i==n){
            return m-j;
        }
        
        if(j==m){
            return n-i;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int temp_ans=INT_MAX/2;
        temp_ans=min(1+rec(i,j+1,n,m,dp,s1,s2),1+rec(i+1,j,n,m,dp,s1,s2));
        if(s1[i]==s2[j]){
            temp_ans=min(temp_ans,rec(i+1,j+1,n,m,dp,s1,s2));
        }
        return dp[i][j]=temp_ans;
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return rec(0,0,n,m,dp,word1,word2);
    }
};