class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans = -1;
        for(auto num : nums){
            if(ans != num && count == 0){
                ans = num;
                count = 1;
            }
            else{
                if(ans == num){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return ans;
    }
};