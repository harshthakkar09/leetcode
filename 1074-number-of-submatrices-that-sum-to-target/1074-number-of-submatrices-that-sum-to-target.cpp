class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int ans = 0;
        for(int c1 = 0; c1 < m; c1++){
            for(int c2 = c1; c2 < m; c2++){
                unordered_map<int, int> freq;
                freq[0] = 1;
                int sum = 0;
                for(int i = 0; i < n; i++){
                    sum += matrix[i][c2];
                    if(c1 > 0){
                        sum -= matrix[i][c1-1];
                    }
                    ans += freq[sum - target];
                    freq[sum]++;
                }
            }
        }
        return ans;
    }
};