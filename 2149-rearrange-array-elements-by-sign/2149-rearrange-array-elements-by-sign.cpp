class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto num : nums){
            if(num > 0){
                pos.push_back(num);
            }
            else{
                neg.push_back(num);
            }
        }
        int n = pos.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};