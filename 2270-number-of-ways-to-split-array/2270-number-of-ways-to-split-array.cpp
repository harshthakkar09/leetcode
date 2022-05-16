typedef long long ll;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<ll> pre(n,0);
        vector<ll> suf(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
        for(int i=0;i<n-1;i++){
            // cout<<"i "<<i<<" pre[i] "<<pre[i]<<" suf[i] "<<suf[i]<<"\n";
            if(pre[i]>=(suf[i]-nums[i])){
                ans++;
            }
        }
        return ans;
    }
};