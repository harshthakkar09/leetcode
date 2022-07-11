class Solution {
public:
    int ans = 0;
    
    void dfs(int ind, int curTime, int curVal, int maxTime, vector<int>& value, vector<pair<int,int>> adj[]){
        if(curTime > maxTime){
            return;
        }
        curVal += value[ind];
        if(ind == 0){
            ans = max(ans, curVal);
        }
        int temp = value[ind];
        value[ind] = 0;
        for(auto neg: adj[ind]){
            dfs(neg.first, curTime + neg.second, curVal, maxTime, value, adj);
        }
        value[ind] = temp;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int,int>> graph[n];
        for(auto edge:edges){
            int u = edge[0], v = edge[1], t = edge[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        dfs(0, 0, 0, maxTime, values, graph);
        return ans;
    }
};