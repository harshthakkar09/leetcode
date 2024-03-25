class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            // cout<<"i: "<<i<<"\n";
            int num = abs(nums[i]);
            // cout<<"num: "<<num<<"\n";
            if(nums[num - 1] > 0){
                nums[num - 1] = -1 * nums[num - 1];
            }
            else{
                ans.push_back(num);
            }
        }
        return ans;
    }
};