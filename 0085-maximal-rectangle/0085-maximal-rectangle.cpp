class Solution {
public:
    
    int solve(vector<int>& arr, int n){
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[i] <= arr[st.top()])){
                int t = st.top(), height, width;
                st.pop();
                height = arr[t];
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                ans = max(ans, width * height);
            }
            st.push(i);
        }
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