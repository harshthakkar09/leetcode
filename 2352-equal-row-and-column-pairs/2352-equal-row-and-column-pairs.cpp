class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        unordered_map<string, int> row_freq;
        unordered_map<string, int> col_freq;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp += to_string(grid[i][j]) + " ";
            }
            row_freq[temp]++;
        }
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp += to_string(grid[j][i]) + " ";
            }
            col_freq[temp]++;
        }
        for(auto it: row_freq){
            int freq1 = it.second, freq2 = col_freq[it.first];
            ans += (freq1 * freq2);
        }
        return ans;
    }
};