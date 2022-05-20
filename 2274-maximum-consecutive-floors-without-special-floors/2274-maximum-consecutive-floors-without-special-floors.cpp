class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans=0,n=special.size();
        sort(special.begin(),special.end());
        for(int i=1;i<n;i++){
            ans=max(ans,special[i]-special[i-1]-1);
        }
        ans=max(ans,special[0]-bottom);
        ans=max(ans,top-special[n-1]);
        return ans;
    }
};