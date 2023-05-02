//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool solve(int tar, vector<int>& arr, int n, int k){
        int curSum = 0, count = 0;
        for(int i = 0; i < n; i++){
            curSum += arr[i];
            if(curSum >= tar){
                count++;
                curSum = 0;
            }
        }
        return count >= k;
    }
    
    
    int maxSweetness(vector<int>& sweetness, int n, int k) {
        int  l = 1, r = INT_MAX, ans;
        while(l <= r){
            int m = (l + r) / 2;
            if(solve(m, sweetness, n, k + 1)){
                ans = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
    // Write your code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends