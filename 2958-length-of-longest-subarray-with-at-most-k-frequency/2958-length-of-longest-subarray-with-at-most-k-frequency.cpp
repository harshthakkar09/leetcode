class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0, n = nums.size(), j = 0;
        for(int i = 0; i < n; i++){
            // cout<<"i: "<<i<<"\n";
            int num = nums[i];
            // cout<<"num: "<<num<<"\n";
            freq[num]++;
            // cout<<"freq: "<<freq[num]<<"\n";
            while(freq[num] > k){
                // cout<<"inside while"<<"\n";
                freq[nums[j]]--;
                // cout<<"j: "<<j<<"\n";
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};