class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(n%2==0){
            int target=nums[n/2],ans=0;
            for(int i=0;i<n;i++){
                ans+=abs(nums[i]-target);
            }
            return ans;
        }
        else{
            int target1=nums[n/2],target2=nums[(n/2)-1],ans1=0,ans2=0;
            for(int i=0;i<n;i++){
                ans1+=abs(nums[i]-target1);
                ans2+=abs(nums[i]-target2);
            }
            return min(ans1,ans2);
        }
    }
};