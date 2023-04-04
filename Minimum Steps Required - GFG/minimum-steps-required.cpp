//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int a = 0, b = 0, n = str.size();
    if(str[0] == 'a'){
        a++;
    }
    else{
        b++;
    }
    for(int i = 1; i < n; i++){
        if(str[i] == 'a' && str[i - 1] == 'b'){
            a++;
        }
        if(str[i] == 'b' && str[i - 1] == 'a'){
            b++;
        }
    }
    return min(a, b) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends