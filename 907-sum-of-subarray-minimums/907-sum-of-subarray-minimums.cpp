typedef long long ll;
class Solution {
public:
    ll sum(ll a, ll b){
        return (a + b) % 1000000007;
    }
    
    ll mul(ll a, ll b){
        return (a * b) % 1000000007;
    }
    
    ll sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0;
        vector<ll> preSmall(n);
        vector<ll> nextSmall(n);
        for(int i = 1; i <= n; i++){
            preSmall[i - 1] = i;
        }
        for(int i = 1; i <= n; i++){
            nextSmall[n - i] = i;
        }
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            if(!s.empty()){
                preSmall[i] = (i - s.top());
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                nextSmall[i] = (s.top() - i);
            }
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            ans = sum(ans, mul(preSmall[i], mul(nextSmall[i], arr[i])));
        }
        return ans;
    }
};