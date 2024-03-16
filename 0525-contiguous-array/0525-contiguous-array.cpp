class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, prefixSum = 0, n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                prefixSum += 1;
            }
            else{
                prefixSum -= 1;
            }
            if(freq.find(prefixSum) != freq.end()){
                ans = max(ans, i - freq[prefixSum]);
            }
            else{
                freq[prefixSum] = i;
            }
        }
        return ans;
    }
};