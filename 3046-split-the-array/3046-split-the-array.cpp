class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            if(freq.find(num) != freq.end() && freq[num] == 2){
                return false;
            }
            freq[num]++;
        }
        return true;
    }
};