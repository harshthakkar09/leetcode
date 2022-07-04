class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size(),ans=n,peak=0,valley=0;
        for(int i=1;i<n;){
            peak=0,valley=0;
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            
            while(i<n && arr[i]>arr[i-1]){
                peak++;
                i++;
                ans+=peak;
            }
            
            while(i<n && arr[i-1]>arr[i]){
                valley++;
                i++;
                ans+=valley;
            }
            
            ans-=min(peak,valley);
        }
        return ans;
    }
};