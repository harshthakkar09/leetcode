#define mod 1000000007
typedef long long ll;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<int> hc,vc;
        hc.push_back(0);
        vc.push_back(0);
        int hcsize=horizontalCuts.size();
        int vcsize=verticalCuts.size();
        for(int i=0;i<hcsize;i++){
            hc.push_back(horizontalCuts[i]);
        }
        for(int i=0;i<vcsize;i++){
            vc.push_back(verticalCuts[i]);
        }
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int dif1=INT_MIN;
        for(int i=1;i<hc.size();i++){
            int td=(hc[i]-hc[i-1])%mod;
            if(td>dif1){
                dif1=td;
            }
        }
        int dif2=INT_MIN;
        for(int i=1;i<vc.size();i++){
            int td=(vc[i]-vc[i-1])%mod;
            if(td>dif2){
                dif2=td;
            }
        }
        return (long)dif1*dif2%(mod);
    }
};