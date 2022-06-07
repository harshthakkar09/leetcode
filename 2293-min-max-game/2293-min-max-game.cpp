class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> temp;
            bool flag=true;
            for(int i=0;i<nums.size();){
                if(flag){
                    temp.push_back(min(nums[i],nums[i+1]));
                }
                else{
                    temp.push_back(max(nums[i],nums[i+1]));
                }
                i+=2;
                flag=!flag;
            }
            nums=temp;
        }
        return nums[0];
    }
};