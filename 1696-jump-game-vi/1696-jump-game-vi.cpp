#define pii pair<int,int>
class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int ans = nums[0], n = nums.size();
        priority_queue<pii> pq;
        pq.push({nums[0], 0});
        for(int i = 1; i < n; i++){
            while(i - pq.top().second > k){
                pq.pop();
            }
            pii top = pq.top();
            ans = top.first + nums[i];
            pq.push({ans, i});
        }
        return ans;
    }
};