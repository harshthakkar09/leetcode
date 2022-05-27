class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1;
        while(l<=r){
            int m=(l+r)>>1;
            if(nums[m]==target){
                return m;
            }
            if(nums[l]<=nums[m]){
                if(target>=nums[l] && target<=nums[m]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
               if(nums[m]<=target && nums[r]>=target){
                   l=m+1;
               }
               else{
                   r=m-1;     
               }
            }
        }
        return -1;
    }
};