class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0,size=nums.size();
        unordered_set<int> vis;
        for(auto num:nums){
            vis.insert(num);
        }
        for(int i=0;i<size;i++){
            int num=nums[i];
            if(vis.find(num-1)==vis.end()){
                int cur=num,currentAns=0;
                while(vis.find(cur)!=vis.end()){
                    cur++;
                    currentAns++;
                }
                ans=max(ans,currentAns);
            }
        }
        return ans;
    }
};