//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string, int> freq;
        for(auto it : arr){
            string rev = it;
            reverse(rev.begin(), rev.end());
            if(freq.find(rev) != freq.end()){
                freq[rev]--;
                if(freq[rev] == 0){
                    freq.erase(rev);
                }
            }
            else{
                freq[it]++;
            }
        }
        if(freq.size() == 0){
            return true;
        }
        if(freq.size() == 1){
            string cur = freq.begin()->first;
            string rev = cur;
            reverse(rev.begin(), rev.end());
            return cur == rev;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends