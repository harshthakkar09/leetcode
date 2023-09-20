class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back(make_pair(nums[i],i));
        }
        sort(vp.begin(),vp.end());
        int l=0,r=n-1;
        vector<int> ans(2);
        while(true){
            if((vp[l].first+vp[r].first)==target){
                ans[0]=vp[l].second;
                ans[1]=vp[r].second;
                return ans;
                break;
            }
            else if((vp[l].first+vp[r].first)>target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};