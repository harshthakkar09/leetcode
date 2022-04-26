class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        vector<vector<int>> map(101);
        for(auto rec:rectangles){
            int x=rec[0];
            int y=rec[1];
            map[y].push_back(x);
        }
        for(int i=0;i<101;i++){
            sort(map[i].begin(),map[i].end());
        }
        int n=points.size();
        for(int i=0;i<n;i++){
            int px=points[i][0];
            int py=points[i][1];
            int cnt=0;
            for(int j=py;j<101;j++){
                int ind=lower_bound(map[j].begin(),map[j].end(),px)-map[j].begin();
                cnt+=map[j].size()-ind;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};