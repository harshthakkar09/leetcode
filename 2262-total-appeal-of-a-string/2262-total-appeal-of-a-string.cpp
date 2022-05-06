typedef long long ll;
class Solution {
public:
    ll count(string st,char ch){
        ll len = st.length(),res=0,cnt=0;
        for(int i=0;i<len;i++){
            if(st[i]==ch){
                res+= ((cnt)*(cnt+1))/2;
                cnt=0;
            }else
                cnt++;
        }
        res+= ((cnt)*(cnt+1))/2;
        return ((len)*(len+1))/2-res;
    }
    long long appealSum(string st) {
        ll total_cnt=0;
        for(char ch='a';ch<='z';ch++){
            total_cnt+=count(st,ch);
        }
        return total_cnt;
    }
};