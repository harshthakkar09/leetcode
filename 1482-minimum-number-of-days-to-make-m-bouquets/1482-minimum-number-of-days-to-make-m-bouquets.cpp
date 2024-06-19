typedef long long ll;
class Solution {
public:
    
    bool check(vector<int>& arr, int n, int m, int k, int mid){
        int freq = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] <= mid){
                freq++;
                if(freq == k){
                    count++;
                    freq = 0;
                }
            }
            else{
                freq = 0;
            }
        }
        return count >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), left = 1, right = 1e9, ans = -1;
        if(((ll)m * (ll)k) > (ll)n){
            return -1;
        }
        while(left <= right){
            int mid = (left + right) / 2;
            if(check(bloomDay, n, m, k, mid)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};