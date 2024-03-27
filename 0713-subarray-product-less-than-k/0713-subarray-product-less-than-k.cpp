class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1){
            return 0;
        }
        
        int n = nums.size(), left = 0, right = 0, product = 1, ans = 0;
        while(right < n){
            // cout<<"left "<<left<<" right "<<right<<"\n";
            product *= nums[right];
            // cout<<"product "<<product<<"\n";
            while(product >= k){
                product /= nums[left];
                left++;
            }
            // cout<<"ans time left "<<left<<" right "<<right<<"\n";
            ans += (right - left + 1);
            // cout<<"ans "<<ans<<"\n";
            right++;
        }
        return ans;
    }
};