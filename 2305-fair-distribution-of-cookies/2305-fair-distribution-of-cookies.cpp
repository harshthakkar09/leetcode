class Solution {
public:
    int ans=INT_MAX;
    
    void rec(int ind,vector<int>& arr,int n,int k,vector<int>& v){
        if(ind==n){
            int tans=INT_MIN;
            for(int i=0;i<k;i++){
                tans=max(tans,v[i]);
            }
            ans=min(ans,tans);
            return;
        }
        for(int i=0;i<k;i++){
            v[i]+=arr[ind];
            rec(ind+1,arr,n,k,v);
            v[i]-=arr[ind];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        int n=cookies.size();
        rec(0,cookies,n,k,v);
        return ans;
    }
};