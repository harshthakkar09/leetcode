class Solution {
public:
    int countAsterisks(string s) {
        int n=s.size(),count=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                count++;
            }
            if(s[i]=='*' && (count%2)==0){
                ans++;
            }
        }
        return ans;
    }
};