typedef long long ll;
class Solution {
public:
    ll count=0;
    
    void dfs(int ind,vector<bool>& vis,vector<vector<int>>& graph){
        vis[ind]=true;
        count++;
        for(auto neg:graph[ind]){
            if(!vis[neg]){
                dfs(neg,vis,graph);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll ans=0;
        vector<vector<int>> neg(n);
        for(auto edge:edges){
            int x=edge[0],y=edge[1];
            neg[x].push_back(y);
            neg[y].push_back(x);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count=0;
                dfs(i,vis,neg);
                ans+=count*(n-count);
            }
        }
        return ans/2;
    }
};