class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size(), i = 0, j = 1;
        vector<string> ans;
        stack<int> s;
        while(i < m){
            // cout<<"j: "<<j<<"\n";
            if(target[i] == j){
                if(i == 0){
                    while(!s.empty()){
                        s.pop();
                        ans.push_back("Pop");
                    }
                }
                else{
                    while(!s.empty() && target[i - 1] != s.top()){
                        s.pop();
                        ans.push_back("Pop");
                    }
                }
                s.push(j);
                ans.push_back("Push");
                i++;
                j++;
            }
            else{
                s.push(j);
                j++;
                ans.push_back("Push");
            }
        }
        return ans;
    }
};