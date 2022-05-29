class Solution {
public:
    int max(int a,int b){
        if(a>=b){
            return a;
        }
        return b;
    }
    
    int maxProduct(vector<string>& words) {
        vector<vector<int>> track(26,vector<int> (1000));
        int n=words.size();
        for(int i=0;i<n;i++){
            int m=words[i].size();
            for(int j=0;j<m;j++){
                track[words[i][j]-'a'][i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                bool flag=false;
                for(int k=0;k<26;k++){
                    if(track[k][i] && track[k][j]){
                        flag=true;
                        continue;
                    }
                }
                if(!flag){  
                    ans=max(ans,words[i].size()*words[j].size());    
                }
            }
        }
        return ans;
    }
};