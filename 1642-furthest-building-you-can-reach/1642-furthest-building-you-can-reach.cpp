class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n - 1; i++){
            int d = heights[i + 1] - heights[i];
            if(d > 0){
                pq.push(d);
            }
            if(pq.size() > ladders){
                int t = pq.top();
                pq.pop();
                bricks -= t;
            }
            if(bricks < 0){
                return i;
            }
        }
        return n - 1;
    }
};