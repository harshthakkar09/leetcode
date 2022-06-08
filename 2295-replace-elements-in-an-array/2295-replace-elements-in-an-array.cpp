class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> um;
        int n=nums.size();
        for(int i=0;i<n;i++){
            um[nums[i]]=i;
        }
        for(auto operation:operations){
            int op1=operation[0],op2=operation[1],pos;
            pos=um[op1];
            nums[um[op1]]=op2;
            um.erase(op1);
            um[op2]=pos;
        }
        return nums;
    }
};