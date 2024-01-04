class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int num : nums){
            um[num]++;
        }
        int ans = 0;
        for(auto it : um){
            int fre = it.second;
            if(fre == 1){
                return -1;
            }
            else{
                if(fre % 3 == 0){
                    ans += (fre / 3);
                }
                else{
                    ans += ((fre + 3) / 3);
                }
            }
        }
        return ans;
    }
};