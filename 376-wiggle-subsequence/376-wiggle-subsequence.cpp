class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        else{
            vector<bool> track;
            for(int i=1;i<n;i++){
                if(nums[i-1]>nums[i]){
                    track.push_back(true);
                }
                else if(nums[i]>nums[i-1]){
                    track.push_back(false);
                }
            }
            int ans=1;
            int m=track.size();
            for(int i=1;i<m;i++){
                if(track[i]!=track[i-1]){
                    ans++;
                }
            }
            if(track.size()==0){
                return 1;
            }
            else{
                return ans+1;
            }
        }
    }
};