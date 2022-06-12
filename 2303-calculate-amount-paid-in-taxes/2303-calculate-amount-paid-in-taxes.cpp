class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans=0.0;
        int n=brackets.size(),i=0,pre=0;
        while(i<n){
            int earning=brackets[i][0];
            int percent=brackets[i][1];
            ans+=(min(earning,income)-pre)*((double)percent/100.0);
            pre=earning;
            if(earning>=income){
                return ans;
            }
            i++;
        }
        return ans;
    }
};