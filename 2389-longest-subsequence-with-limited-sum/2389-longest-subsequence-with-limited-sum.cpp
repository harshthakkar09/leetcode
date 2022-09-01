class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> sum(n);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i - 1] + nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int ind = lower_bound(sum.begin(), sum.end(), queries[i]) - sum.begin();
            if(ind < sum.size() && sum[ind] == queries[i]){
                ans.push_back(ind + 1);
            }
            else{
                ans.push_back(ind);
            }
        }
        return ans;
    }
};