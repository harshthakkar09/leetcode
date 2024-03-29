typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans = 0, i = 0, j = 0, count = 0, maxNum = INT_MIN, n = nums.size();
        for(auto num : nums){
            maxNum = max((ll)num, maxNum);
        }
        for(ll j = 0; j < n; j++){
            if(nums[j] == maxNum){
                count++;
            }
            if(count >= k){
                while(count >= k){
                    ans += (n - j);
                    if(nums[i] == maxNum){
                        count--;
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};