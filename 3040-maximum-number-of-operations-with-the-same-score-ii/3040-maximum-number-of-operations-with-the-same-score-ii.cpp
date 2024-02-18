class Solution {
public:
    
    unordered_map<string, int> dp;
    
    string makeKey(int a, int b){
        return to_string(a) + " " + to_string(b);
    }
    
    int helper(int preSum, int start, int end, int n, vector<int>& nums){
        if(!(start >= 0 && start < n && end >= 0 && end < n) || start >= end){
            return 0;
        }
        
        string key = makeKey(start, end);
        if(dp.find(key) != dp.end()){
            return dp[key];
        }
        
        int ans = 0;
        if(start + 1 < n && nums[start] + nums[start + 1] == preSum){
            ans = max(ans, 1 + helper(preSum, start + 2, end, n, nums));
        }
        
        if(end - 1 >= 0 && nums[end] + nums[end - 1] == preSum){
            ans = max(ans, 1 + helper(preSum, start, end - 2, n, nums));
        }
        
        if(nums[start] + nums[end] == preSum){
            ans = max(ans, 1 + helper(preSum, start + 1, end - 1, n, nums));
        }
        
        // cout<<"preSum: "<<preSum<<" start "<<start<<" end "<<end<<" ans: "<<ans<<"\n";
        return dp[key] = ans;
    }
    
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        return 1 + max(max(helper(nums[0] + nums[1], 2, n - 1, n, nums), helper(nums[n - 1] + nums[n - 2], 0, n - 3, n, nums)), helper(nums[0] + nums[n - 1], 1, n - 2, n, nums));
    }
};