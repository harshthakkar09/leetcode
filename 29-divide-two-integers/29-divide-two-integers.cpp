typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==-1 && dividend==INT_MIN){
            return INT_MAX;
        }
        
        if(divisor==1){
            return dividend;
        }
        
        if(divisor==-1){
            return -dividend;
        }
        
        bool dividend_sign=false;
        bool divisor_sign=false;
        if(divisor<0){
            divisor_sign=true;
        }
        if(dividend<0){
            dividend_sign=true;
        }
        divisor=abs(divisor);
        dividend=abs(dividend);
        cout<<divisor<<" "<<dividend<<"\n";
        int ans;
        ll l=0,r=dividend;
        // cout<<l<<" "<<r<<"\n";
        while(l<=r){
            ll mid=(l+r)>>1;
            // cout<<l<<" "<<mid<<" "<<r<<"\n";
            if(mid*divisor<=dividend){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(dividend_sign!=divisor_sign){
            return -1*ans;
        }
        return ans;
    }
};