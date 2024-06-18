class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({difficulty[i], profit[i]});
        }
        // cout<<"pair created"<<"\n";
        sort(vp.begin(), vp.end());
        // cout<<"sorted"<<"\n";
        int maxDif = vp[n - 1].first;
        // cout<<"maxDif "<<maxDif<<"\n";
        vector<int> newProfit(maxDif + 1);
        for(int i = 0; i < n; i++){
            newProfit[vp[i].first] = vp[i].second;
        }
        for(int i = 1; i <= maxDif; i++){
            newProfit[i] = max(newProfit[i], newProfit[i - 1]);
            // cout<<"i: "<<i<<" profit "<<newProfit[i]<<"\n";
        }
        // cout<<"new profit calculated"<<"\n";
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += newProfit[min(worker[i], maxDif)];
        }
        return ans;
    }
};