//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end());
        vector<int> profit(n);
        profit[n - 1] = ranges[n - 1][2];
        for(int i = n - 2; i >= 0; i--){
            profit[i] = max(profit[i + 1], ranges[i][2]);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = ranges[i][2], low = i + 1, high = n - 1, temp = 0, mid;
            while(high >= low){
                mid = (low + high) / 2;
                if(ranges[i][1] <= ranges[mid][0]){
                    high = mid - 1;
                    temp = profit[mid];
                }
                else{
                    low = mid + 1;
                }
            }
            sum += temp;
            ans = max(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends