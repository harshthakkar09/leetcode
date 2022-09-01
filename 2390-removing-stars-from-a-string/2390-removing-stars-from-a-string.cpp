class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            char top = st.top();
            ans += top;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};