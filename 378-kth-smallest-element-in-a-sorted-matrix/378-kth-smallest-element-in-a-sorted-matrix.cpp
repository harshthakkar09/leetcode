class Solution {
public:
    
    int count(vector<vector<int>>& matrix, int mid, int n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            int ub = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            ans += ub;
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), left = matrix[0][0], right = matrix[n - 1][n - 1], ans;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(count(matrix, mid, n) >= k){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};