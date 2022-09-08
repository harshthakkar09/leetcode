class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), nn = 2 * n - 1;
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans;
        stack<int> s;
        for(int i = nn; i >= 0; i--){
            int curAns = -1;
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            if(!s.empty()){
                curAns = s.top();
            }
            s.push(nums[i]);
            if(i < n){
               ans.push_back(curAns); 
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};