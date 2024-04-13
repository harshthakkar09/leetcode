class Solution {
public:
    
    int solve(vector<int>& arr, int n){
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            }
            else{
                left[i] = st.top() + 1;
            }
            st.push(i);
            // cout<<"i: "<<i<<" left[i] "<<left[i]<<"\n";
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n - 1;
            }
            else{
                right[i] = st.top() - 1;
            }
            st.push(i);
            // cout<<"i: "<<i<<" right[i] "<<right[i]<<"\n";
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, (right[i] - left[i] + 1) * arr[i]);
        }
        // cout<<"ans: "<<ans<<"\n";
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> sum(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    sum[j] = sum[j] + 1;
                }
                else{
                    sum[j] = 0;
                }
            }
            // cout<<"i: "<<i<<"\n";
            ans = max(ans, solve(sum, m));
        }
        return ans;
    }
};