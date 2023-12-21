class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> pointx;
        for(auto point : points){
            pointx.insert(point[0]);
        }
        vector<int> pointxVec;
        for(auto it : pointx){
            pointxVec.push_back(it);
        }
        int n = pointxVec.size(), ans = 0;
        for(int i = 1; i < n; i++){
            ans = max(ans, pointxVec[i] - pointxVec[i - 1]);
        }
        return ans;
    }
};