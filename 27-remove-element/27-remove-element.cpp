class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        bool flag=false;
        int pre=-1,n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==val){    
                flag=true;
                continue;
            }
            else if(flag && nums[i]!=val){
                cnt++;
                swap(nums[i],nums[pre+1]);
                pre++;
            }
            else{
                cnt++;
                pre++;
            }
        }
        return cnt;
    }
};