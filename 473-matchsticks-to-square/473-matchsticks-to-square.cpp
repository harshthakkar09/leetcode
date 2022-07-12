class Solution {
public:
    
    bool rec(int ind, vector<int>& sticks, vector<int>& sum, int n, int target){
        if(ind == n){
            return sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3];
        }
        for(int i = 0; i < 4; i++){
            if(sum[i] + sticks[ind] > target){
                continue;
            }
            sum[i] += sticks[ind];
            if(rec(ind + 1, sticks, sum, n, target)){
                return true;
            }
            sum[i] -= sticks[ind];
        }
        return false;
    }
    
    bool makesquare(vector<int>& sticks) {
        int n = sticks.size(), sum = 0;
        sort(sticks.begin(), sticks.end(), greater<int>());
        for(int i = 0; i < n; i++){
            sum += sticks[i];
        }
        if(sum%4 == 0){
            int target = sum / 4;
            vector<int> v{0, 0, 0, 0};
            return rec(0, sticks, v, n, target);
        }
        else{
            return false;
        }
    }
};