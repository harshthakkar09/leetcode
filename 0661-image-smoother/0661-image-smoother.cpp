// typedef long long ll;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int count = 0, sum = 0;
                for(int k = 0; k < 9; k++){
                    int ni = i + dir[k][0], nj = j + dir[k][1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                        count++;
                        // cout<<"ni: "<<ni<<" nj: "<<nj<<"\n";
                        // cout<<"img[ni][nj]: "<<img[ni][nj]<<"\n";
                        sum += img[ni][nj];
                    }
                }
                ans[i][j] = (sum / count);
            }
        }
        return ans;
    }
};