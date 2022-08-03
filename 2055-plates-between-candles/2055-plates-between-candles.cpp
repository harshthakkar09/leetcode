class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> candles, ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                candles.push_back(i);
            }
        }
        for(auto query: queries){
            int start = query[0], end = query[1];
            int left = lower_bound(candles.begin(), candles.end(), start) - candles.begin();
            int right = upper_bound(candles.begin(), candles.end(), end) - candles.begin() - 1;
            if(right > left){
                ans.push_back(candles[right] - candles[left] - (right - left));
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};