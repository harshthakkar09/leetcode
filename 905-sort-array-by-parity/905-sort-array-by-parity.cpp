class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans;
        for(auto i:A){
            if(i%2==0){
                ans2.push_back(i);
            }
            else{
                ans1.push_back(i);
            }
        }
        for(auto i:ans2){
            ans.push_back(i);
        }
        for(auto i:ans1){
            ans.push_back(i);
        }
        return ans;
    }
};