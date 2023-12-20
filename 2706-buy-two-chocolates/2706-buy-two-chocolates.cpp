class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size(), ans = money, priceMin = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(money >= (prices[i] + prices[j])){
                    if(prices[i] + prices[j] < priceMin){
                        priceMin = prices[i] + prices[j];
                        ans = money - priceMin;
                    }
                }
            }
        }
        return ans;
    }
};