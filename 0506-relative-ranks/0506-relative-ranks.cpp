class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreMap;
        vector<string> ans(n, "");
        for(int i = 0; i < n; i++){
            scoreMap.push_back({score[i], i});
        }
        sort(scoreMap.begin(), scoreMap.end(), greater<pair<int, int>>());
        // cout<<"sorting done"<<"\n";
        for(int i = 0; i < n; i++){
            // cout<<"i: "<<i<<"\n";
            if(i == 0){
                ans[scoreMap[i].second] = "Gold Medal";
            }
            else if(i == 1){
                ans[scoreMap[i].second] = "Silver Medal";
            }
            else if(i == 2){
                ans[scoreMap[i].second] = "Bronze Medal";
            }
            else{
                ans[scoreMap[i].second] = to_string(i + 1);
            }
        }
        return ans;
    }
};