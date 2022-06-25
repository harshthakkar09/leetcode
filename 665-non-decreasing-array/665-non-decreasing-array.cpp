class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),count=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                if(i>=2 && nums[i-2]>nums[i]){
                    nums[i]=nums[i-1];
                }
                else{
                    nums[i-1]=nums[i];
                }
                count++;
            }
        }
        return count<=1;
    }
};