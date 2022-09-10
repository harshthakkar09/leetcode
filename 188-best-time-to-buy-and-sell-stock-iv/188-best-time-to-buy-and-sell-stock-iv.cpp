class Solution {
public:
    
    unordered_map<string,int> dp;
    
    int rec(vector<int>& prices,int ind,int buy,int ntx,int k){
        
        string s=to_string(ind)+" "+to_string(buy)+" "+to_string(ntx);
        
        int len=prices.size();
        if(ind>=len || ntx>=k){
            return 0;
        }
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        
        if(buy==1){
            return dp[s]=max(-prices[ind]+rec(prices,ind+1,0,ntx,k),rec(prices,ind+1,1,ntx,k));
        }
        else{
            return dp[s]=max(+prices[ind]+rec(prices,ind+1,1,ntx+1,k),rec(prices,ind+1,0,ntx,k));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        if(k>=prices.size()/2){
            int pro=0;
            for(int i=1;i<prices.size();i++){
                if(prices[i]>prices[i-1]){
                    pro+=(prices[i]-prices[i-1]);
                }
            }
            return pro;
        }
        return rec(prices,0,1,0,k);
    }
};