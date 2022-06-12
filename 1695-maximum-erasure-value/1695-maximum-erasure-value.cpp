class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0,cur_sum=0,ans=0;
        vector<int> pre;
        pre.push_back(0);
        unordered_map<int,int> track;
        while(r<n){
            int num=nums[r];
            pre.push_back(num+pre[r]);
            if(track.find(num)!=track.end() && track[num]>=l){
                l=track[num]+1;
            }
            ans=max(ans,pre[r+1]-pre[l]);
            track[num]=r;
            r++;
        }
        return ans;
    }
};