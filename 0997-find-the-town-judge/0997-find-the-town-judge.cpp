class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> graph[n+1];
        vector<int> in(n+1);
        for(auto it:trust){
            in[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0 && graph[i].size()==n-1){
                return i;
            }
        }
        return -1;
    }
};