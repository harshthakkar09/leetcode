//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    int rec(int n, int k, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target < 0){
            return 0;
        }
        
        if(k == 0){
            return target == 0;
        }
        
        if(dp[k][target] != -1){
            return dp[k][target];
        }
        
        int tans = 0;
        for(int i = 0; i < n; i++){
            tans = tans | rec(n, k - 1, target - coins[i], coins, dp);
        }
        return dp[k][target] = tans;
    }
  
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        // code here
        vector<vector<int>> dp(k + 1, vector<int> (target + 1, -1));
        return rec(n, k, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends