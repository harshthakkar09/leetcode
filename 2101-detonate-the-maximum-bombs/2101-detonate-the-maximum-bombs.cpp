typedef long long ll;
class Solution {
public:
    
    void dfs(int ind, vector<vector<int>>& graph, vector<bool>& vis, int& count){
        for(int neg : graph[ind]){
            if(!vis[neg]){
                vis[neg] = true;
                count++;
                dfs(neg, graph, vis, count);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++){
            int x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            for(int j = 0; j < n; j++){
                int nx = bombs[j][0], ny = bombs[j][1];
                if((ll)r * (ll)r >= pow((ll)(x - nx), (ll)2) + pow(ll(y - ny), (ll)2)){
                    graph[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
                vector<bool> vis(n, false);
                int count = 0;
                vis[i] = true;
                count++;
                dfs(i, graph, vis, count);
                ans = max(ans, count);
            
        }
        return ans;
    }
};