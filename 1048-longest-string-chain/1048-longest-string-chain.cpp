class Solution {
public:
    
    static bool cmp(string& a,string& b){
        return a.size()>b.size();
    }
    
    int max(int a,int b){
        if(a>=b){
            return a;
        }
        return b;
    }
    
    int rec(int i,int j,int n,int m,string& a,string& b,vector<vector<int>>& dp){
        if(i==n || j==m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MIN;
        // cout<<"a[i] "<<a[i]<<" b[j] "<<b[j]<<"\n";
        if(a[i]==b[j]){
            ans=max(ans,1+rec(i+1,j+1,n,m,a,b,dp));
        }
        else{
            ans=max(ans,rec(i+1,j,n,m,a,b,dp));
            ans=max(ans,rec(i,j+1,n,m,a,b,dp));
        }
        // cout<<"i "<<i<<" j "<<j<<" ans "<<ans<<"\n";
        return dp[i][j]=ans;
    }
    
    int lcs(string& a,string& b){
        // cout<<"a "<<a<<" b "<<b<<"\n";
        int na=a.size(),nb=b.size();
        vector<vector<int>> dp(na,vector<int> (nb,-1));
        int ans=rec(0,0,na,nb,a,b,dp);
        // cout<<"a "<<a<<" b "<<b<<" ans "<<ans<<"\n";
        return ans;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size(),maxlen=0,ans=0;
        sort(words.begin(),words.end(),cmp);
        for(auto word:words){
            maxlen=max(word.size(),maxlen);
        }
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            if(words[i].size()<maxlen){
                for(int j=i-1;j>=0;j--){
                    // cout<<"lcs(words[i],words[j]) "<<lcs(words[i],words[j])<<" words[i].size() "<<words[i].size()<<"\n";
                    if((words[j].size()-1)==words[i].size() && lcs(words[i],words[j])==words[i].size()){
                        // cout<<"inside if"<<"\n";
                        // cout<<"i "<<i<<" dp[i] "<<dp[i]<<"\n";
                        // cout<<"dp[j]+1 "<<dp[j]+1<<"\n";
                        dp[i]=max(dp[j]+1,dp[i]);
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};