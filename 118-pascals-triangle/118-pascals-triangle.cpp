class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i < num; i++){
            vector<int> row_ans;
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    row_ans.push_back(ans[i - 1][0]);
                }
                else if(j == i){
                    row_ans.push_back(ans[i - 1][i - 1]);
                }
                else{
                    row_ans.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(row_ans);
        }
        return ans;
    }
};