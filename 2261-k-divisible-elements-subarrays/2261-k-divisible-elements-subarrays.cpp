class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        unordered_set<string> us;
        for(int i=0;i<n;i++){
            string tans="";
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    cnt++;
                }
                
                if(cnt>k){
                    break;
                }
                
                tans+=to_string(nums[j]);
                tans+=" ";
                
                us.insert(tans);
            }
        }
        return us.size();
    }
};