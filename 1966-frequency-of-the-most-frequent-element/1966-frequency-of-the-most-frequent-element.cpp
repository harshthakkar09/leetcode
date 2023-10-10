typedef long long ll;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, ans = 0, right = 0;
        ll sum = nums[0];
        while(right < n){
            if((ll)((ll)(right - left + 1) * (ll)nums[right]) <= (ll)(sum + k)){
                ans = max(ans, right - left + 1);
                right++;
                if(right < n){
                    sum += nums[right];
                }
            }
            else{
                sum -= nums[left];
                left++;
            }
        }
        return ans;
    }
};