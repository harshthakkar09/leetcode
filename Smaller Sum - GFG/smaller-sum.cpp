//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    typedef long long ll;
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        unordered_map<ll, ll> preSums;
        map<ll, ll> freq;
        for(auto num : arr){
            freq[num]++;
        }
        ll preSum = 0;
        for(auto it : freq){
            preSums[it.first] = preSum;
            preSum += (it.first * it.second);
        }
        vector<ll> ans;
        for(auto num : arr){
            ans.push_back(preSums[num]);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends