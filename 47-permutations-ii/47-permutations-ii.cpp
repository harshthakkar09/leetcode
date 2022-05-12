class Solution {
public:
    void rec(int ind,vector<int>& nums,int n,vector<vector<int>>& ans){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> us;
        for(int i=ind;i<n;i++){
            if(us.find(nums[i])!=us.end()){
                continue;
            }
            us.insert(nums[i]);
            swap(nums[i],nums[ind]);
            rec(ind+1,nums,n,ans);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        rec(0,nums,n,ans);
        return ans;
    }
};