class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if((n % 2) == 1){
            return {};
        }
        unordered_map<int, int> track;
        for(auto num: changed){
            track[num]++;
        }
        vector<int> nums;
        for(auto it: track){
            nums.push_back(it.first);
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(auto num: nums){
            if(track[2 * num] < track[num]){
                return {};
            }
            for(int i = 0; i < track[num]; i++){
                track[2 * num]--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};