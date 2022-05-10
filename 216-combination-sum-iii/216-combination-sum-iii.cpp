class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int>& ds,int num,int k,int n){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=num;i<=9;i++){
            ds.push_back(i);
            rec(ans,ds,i+1,k,n-i);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        rec(ans,ds,1,k,n);
        return ans;
    }
};