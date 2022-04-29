class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<graph.size() ;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int topn=q.front();
                    q.pop();
                    int topc=color[topn];
                    for(auto it:graph[topn]){
                        if(color[it]==-1){
                            color[it]=1-topc;
                            q.push(it);
                        }
                        else{
                            if(color[it]==topc){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};