class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n + 2, 0);
        for(auto edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(int i = 1; i <= n + 1; i++){
            // cout<<"i "<<i<<" degree[i] "<<degree[i]<<" n "<<n<<"\n";
            if(degree[i] == n){
                return i;
            }
        }
        return -1;
    }
};