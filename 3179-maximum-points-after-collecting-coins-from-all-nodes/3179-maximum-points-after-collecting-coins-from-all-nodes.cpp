typedef long long ll;
class Solution {
public:
    ll dp[100005][16];

    ll helper(int node, int par, int fre, vector<vector<ll>>& adj, int n, int k, vector<int>& coins){
        if(dp[node][fre] != -1){
            return dp[node][fre];
        }

        ll nf = fre + 1;
        if(nf > 15){
            nf = 15;
        }
        ll ans1 = (coins[node] >> fre) - k;
        ll ans2 = (coins[node] >> nf);

        for(auto child : adj[node]){
            if(child != par){
                ans1 += helper(child, node, fre, adj, n, k, coins);
                ans2 += helper(child, node, nf, adj, n, k, coins);
            }
        }

        return dp[node][fre] = max(ans1, ans2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<ll>> adj(n + 1);
       memset(dp, -1, sizeof(dp));
        for(auto edge : edges){
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        return helper(0, -1, 0, adj, n, k, coins);
    }
};