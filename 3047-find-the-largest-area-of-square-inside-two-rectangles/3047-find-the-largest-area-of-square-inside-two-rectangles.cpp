typedef long long ll;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int minX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int minY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int maxX = min(topRight[i][0], topRight[j][0]);
                int maxY = min(topRight[i][1], topRight[j][1]);
                if(minX < maxX && minY < maxY){
                    ll side = min(maxX - minX, maxY - minY);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};