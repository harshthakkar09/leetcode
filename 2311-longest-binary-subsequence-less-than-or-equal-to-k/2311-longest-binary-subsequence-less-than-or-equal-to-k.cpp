typedef long long ll;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int z=0;
        
        for(char c:s){
            if(c=='0'){
                z++;
            }
        }

        int num=0,base=1,len=0;
        for(int i=s.size()-1;i>=0;i--){    
            if(num+base>k){
                break;
            }
            if(s[i]=='1'){
                num+=base;
            }
            else{
                z--;
            }  
            base*=2;
            len++;
        }
        return len+z;
    }
};