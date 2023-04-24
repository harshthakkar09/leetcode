//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans;
        vector<int> pre(n);
        vector<int> suf(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                pre[i] = -1;
            }
            else{
                pre[i] = st.top();                
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                suf[i] = -1;
            }
            else{
                suf[i] = st.top();
            }
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            if(suf[i] == -1 && pre[i] == -1){
                ans.push_back(-1);
            }
            else if(suf[i] == -1){
                ans.push_back(pre[i]);
            }
            else if(pre[i] == -1){
                ans.push_back(suf[i]);
            }
            else{
                if(i - pre[i] == suf[i] - i){
                    if(arr[pre[i]] <= arr[suf[i]]){
                        ans.push_back(pre[i]);
                    }
                    else{
                        ans.push_back(suf[i]);
                    }
                }
                else if(i - pre[i] < suf[i] - i){
                    ans.push_back(pre[i]);
                }
                else{
                    ans.push_back(suf[i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends