class Solution {
public:
    
    void flipBitsOfRow(int rowNum, vector<vector<int>>& grid, int cols){
        for(int i = 0; i < cols; i++){
            if(grid[rowNum][i] == 0){
                grid[rowNum][i] = 1;
            }
            else{
                grid[rowNum][i] = 0;
            }
        }
    }
    
    int countZeroCols(int colNum, vector<vector<int>>& grid, int rows){
        int ans = 0;
        for(int i = 0; i < rows; i++){
            if(grid[i][colNum] == 0){
                ans++;
            }
        }
        return ans;
    }
    
    void flipBitsOfCol(int colNum, vector<vector<int>>& grid, int rows){
        for(int i = 0; i < rows; i++){
            if(grid[i][colNum] == 0){
                grid[i][colNum] = 1;
            }
            else{
                grid[i][colNum] = 0;
            }
        }
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                flipBitsOfRow(i, grid, m);
            }
        }
        for(int i = 0; i < m; i++){
            int numZero = countZeroCols(i, grid, n);
            int numOne = n - numZero;
            if(numZero > numOne){
                flipBitsOfCol(i, grid, n);
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i = 0; i < n; i++){
            int tans = 0;
            for(int j = m - 1; j >= 0; j--){
                if(grid[i][j] == 1){
                    tans += (1 << (m - 1 - j));
                    // cout<<"tans: "<<tans<<"\n";
                }
            }
            // cout<<"tans before adding: "<<tans<<"\n";
            ans += tans;
        }
        return ans;
    }
};