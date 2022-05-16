typedef long long ll;
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num_str=to_string(num);
        int n=num_str.size(),ans=0;
        ll cur=0,mod=1;
        if(k==1){
            for(int i=0;i<n;i++){
                if((num_str[i]-'0')!=0 && num%(num_str[i]-'0')==0){
                    ans++;
                }
            }
            return ans;
        }
        else{
            for(int i=0;i<k;i++){
                cur=(cur*10)+num_str[i]-'0';
                mod=mod*10;
            }
            mod/=10;
            if(num%cur==0){
                ans++;
            }
            for(int i=k;i<n;i++){
                cur=cur%mod;
                cur=(cur*10)+num_str[i]-'0';
                if(cur!=0 && num%cur==0){
                    ans++;
                }
            }
            return ans;    
        }
    }
};