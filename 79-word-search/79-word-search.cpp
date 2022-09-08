class Solution {
public:
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    bool checkValid(int x, int y, int n, int m, vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int ind){
        return x >= 0 && x < n && y >=0 && y < m && !vis[x][y] && board[x][y] == word[ind];
    }
    
    bool wordSearch(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& vis, int n, int m, string& word, int ind, int w){
        if(ind == w){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(checkValid(nx, ny, n, m, board, vis, word, ind)){
                vis[nx][ny] = true;
                if(wordSearch(nx, ny, board, vis, n, m, word, ind + 1, w)){
                    return true;
                }
                vis[nx][ny] = false;
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), w = word.size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(wordSearch(i, j, board, vis, n, m, word, 1, w)){
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};