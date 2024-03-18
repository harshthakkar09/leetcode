class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] < b[1]){
            return true;
        }
        else if(a[1] == b[1]){
            if(a[0] < b[0]){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 1, end = points[0][1], n = points.size();
        // cout<<"end: "<<end<<"\n";
        for(int i = 1; i < n; i++){
            // cout<<"i: "<<i<<"\n";
            if(points[i][0] > end){
                // cout<<"points[i][0] "<<points[i][0]<<"\n";
                ans++;
                end = points[i][1];
                // cout<<"end: "<<end<<"\n";
            }
        }
        return ans;
    }
};