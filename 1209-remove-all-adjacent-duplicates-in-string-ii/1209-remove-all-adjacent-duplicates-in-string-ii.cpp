class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto c:s){
            if(st.empty()){
                st.push({c,1});
            }
            else{
                auto top=st.top();
                char tc=top.first;
                int ts=top.second;
                if(tc==c){
                    st.pop();
                    int ns=ts+1;
                    if(ns!=k){
                        st.push({tc,ns});
                    }
                }
                else{
                    st.push({c,1});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            for(int i=0;i<top.second;i++){
                ans+=top.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};