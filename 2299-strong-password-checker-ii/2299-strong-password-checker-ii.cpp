class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();
        if(n<8){
            return false;
        }
        int upper=0,lower=0,digit=0,special=0;
        for(int i=0;i<n;i++){
            if(password[i]>='a' && password[i]<='z'){
                lower++;
            }
            else if(password[i]>='A' && password[i]<='Z'){
                upper++;
            }
            else if(password[i]>='0' && password[i]<='9'){
                digit++;
            }
            else{
                special++;
            }
            if(i>0 && password[i]==password[i-1]){
                return false;
            }
        }
        if(upper==0 || lower==0 || digit==0 || special==0){
            return false;
        }
        return true;
    }
};