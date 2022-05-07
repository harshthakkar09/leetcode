class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> track(n);
        track[0]=nums[0];
        for(int i=1;i<n;i++){
            track[i]=min(track[i-1],nums[i]);
        }
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>track[i]){
                while(!s.empty() && s.top()<=track[i]){
                    s.pop();
                }
                if(!s.empty() && s.top()<nums[i]){
                    return true;
                }
                s.push(nums[i]);
            }
        }
        return false;
    }
};