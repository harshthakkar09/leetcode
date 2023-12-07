typedef long long ll;
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ind = 0, n = coins.size(), ans = 0;
        ll preSum = 0;
        for(int t = 1; t <= target; t++){
            if(ind < n && t >= coins[ind]){
                preSum += coins[ind];
                ind++;
            }
            else{
                if(preSum >= t){
                    continue;
                }
                preSum += t;
                ans++;
            }
        }
        return ans;
    }
};