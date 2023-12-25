typedef long long ll;
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> mapping;
        for(auto s : original){
            if(mapping.find(s) == mapping.end()){
                mapping[s] = mapping.size();
            }
        }
        for(auto s : changed){
            if(mapping.find(s) == mapping.end()){
                mapping[s] = mapping.size();
            }
        }
        
        int mapSize = mapping.size(), orgLen = original.size();
        vector<vector<ll>> graph(mapSize, vector<ll> (mapSize, LONG_MAX));
        for(int i = 0; i < orgLen; i++){
            string originalStr = original[i];
            string changedStr = changed[i];
            ll costVal = cost[i];
            // cout<<"costVal: "<<costVal<<"\n";
            int originalInt = mapping[originalStr];
            // cout<<"originalInt "<<originalInt<<"\n";
            int changedInt = mapping[changedStr];
            // cout<<"changedInt "<<changedInt<<"\n";
            // cout<<"graph[originalInt][changedInt] "<<graph[originalInt][changedInt]<<"\n";
            graph[originalInt][changedInt] = min(graph[originalInt][changedInt], costVal);
            // cout<<"graph[originalInt][changedInt] "<<graph[originalInt][changedInt]<<"\n";
        }
        
        for(int k = 0; k < mapSize; k++){
            for(int i = 0; i < mapSize; i++){
                for(int j = 0; j < mapSize; j++){
                    if(graph[i][k] < LONG_MAX && graph[k][j] < LONG_MAX){
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                        // cout<<"graph[i][j] "<<graph[i][j]<<"\n";
                    }
                }
            }
        }
        
        unordered_set<int> allLens;
        for(auto s : original){
            allLens.insert(s.size());
        }
        
        int sz = source.size();
        vector<ll> dp(sz + 1, LONG_MAX);
        dp[0] = 0LL;
        
        for(int i = 0; i < sz; i++){
            // cout<<"i: "<<i<<"\n";
            // cout<<"dp[i] "<<dp[i]<<"\n";
            if(dp[i] == LONG_MAX){
                continue;
            }
            
            if(target[i] == source[i]){
                // cout<<"target equal source"<<"\n";
                dp[i + 1] = min(dp[i + 1], dp[i]);
                // cout<<"dp[i + 1] "<<dp[i + 1]<<"\n";
            }
            
            for(int l : allLens){
                if(i + l >= dp.size()){
                    continue;
                }
                
                // cout<<"l: "<<l<<"\n";
                
                string subSource = source.substr(i, l);
                // cout<<"subSource: "<<subSource<<"\n";
                string subTarget = target.substr(i, l);
                // cout<<"subTarget: "<<subTarget<<"\n";
                
                int i1 = -1, i2 = -1;
                if(mapping.count(subSource)){
                    i1 = mapping[subSource];
                }
                if(mapping.count(subTarget)){
                    i2 = mapping[subTarget];
                }
                // cout<<"i1: "<<i1<<" i2 "<<i2<<"\n";
                if(i1 >= 0 && i2 >= 0 && graph[i1][i2] < LONG_MAX){
                    // cout<<"qualified"<<"\n";
                    dp[i + l] = min(dp[i + l], dp[i] + graph[i1][i2]);
                    // cout<<"(i + l) "<<(i + l)<<" dp[i + l] "<<dp[i + l]<<"\n";
                }
            }
        }
         
        if(dp[sz] == LONG_MAX){
            return -1;
        }
        
        return dp[sz];
    }
};