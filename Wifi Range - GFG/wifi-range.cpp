//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                int left = max(i - x, 0);
                int right = min(i + x, n - 1);
                freq[left]++;
                freq[right + 1]--;
            }
        }
        for(int i = 0; i < n; i++){
            if(i > 0){
                freq[i] += freq[i - 1];
            }
            if(freq[i] == 0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends