class Solution {
public:
    int ans = -1;
    
    void dfs(int node, vector<int>& edges, vector<bool>& vis, vector<bool>& cur_cycle, vector<int>& dis, int cur_dis){
        if(node != -1){
            if(!vis[node]){
                vis[node] = true;
                cur_cycle[node] = true;
                dis[node] = cur_dis;
                dfs(edges[node], edges, vis, cur_cycle, dis, cur_dis + 1);
            }
            else if(cur_cycle[node]){
                ans = max(ans, cur_dis - dis[node]);
            }
            cur_cycle[node] = false;
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int number_of_nodes = edges.size();
        vector<bool> vis(number_of_nodes, false);
        vector<bool> cur_cycle(number_of_nodes, false);
        vector<int> dis(number_of_nodes, 0);
        for(int i = 0; i < number_of_nodes; i++){
            if(!vis[i]){
                dfs(i, edges, vis, cur_cycle, dis, 0);
            }
        }
        return ans;
    }
};