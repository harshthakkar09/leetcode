#define mod 1000000007
#define ll long long 
#define pll pair<ll, ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dis(n, LONG_MAX);
        vector<ll> ans(n);
        vector<vector<pll>> adj(n);
        for(auto road : roads){
            int x = road[0], y = road[1], z = road[2];
            adj[x].push_back({z, y});
            adj[y].push_back({z, x});
        }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        ans[0] = 1;
        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            ll src = pq.top().second, d = pq.top().first;
            pq.pop();
            if(d > dis[src]){
                continue;
            }
            for(auto it : adj[src]){
                int nd = it.first, ne = it.second;
                if(dis[ne] > d + nd){
                    dis[ne] = d + nd;
                    ans[ne] = ans[src];
                    pq.push({d + nd, ne});
                }
                else if(dis[ne] == (d + nd)){
                    ans[ne] = (ans[ne] + ans[src]) % mod;
                }
            }
        }
        return ans[n - 1];
    }
};