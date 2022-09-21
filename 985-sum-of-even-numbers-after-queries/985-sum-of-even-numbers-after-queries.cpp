class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), oddSum = 0, evenSum = 0;
        for(int i = 0; i < n; i++){
            if((nums[i] % 2) == 0){
                evenSum += nums[i];
            }
            else{
                oddSum += nums[i];
            }
        }
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            int val = queries[i][0], index = queries[i][1], preNum = nums[index], newNum = nums[index] + val;
            nums[index] = newNum;
            if((preNum % 2) == 0){
                evenSum -= preNum;
            }
            else{
                oddSum -= preNum;
            }
            if((newNum % 2) == 0){
                evenSum += newNum;
            }
            else{
                oddSum += newNum;
            }
            ans[i] = evenSum;
        }
        return ans;
    }
};