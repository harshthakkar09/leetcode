class Solution {
public:
    
    void bfs(int ind,vector<int>& v,vector<bool>& vis,vector<vector<int>>& graph){
        vis[ind]=true;
        queue<int> q;
        q.push(ind);
        v.push_back(ind);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto neg:graph[f]){
                if(!vis[neg]){
                    q.push(neg);
                    vis[neg]=true;
                    v.push_back(neg);
                }
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<vector<int>> graph(n);
        for(auto pair:pairs){
            int x=pair[0];
            int y=pair[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<bool> vis(n,false);
        vector<vector<int>> cycles;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> cycle;
                bfs(i,cycle,vis,graph);
                cycles.push_back(cycle);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            ans+='a';
        }
        for(auto cycle:cycles){
            string tans="";
            vector<int> places;
            for(auto ind:cycle){
                tans+=s[ind];
                places.push_back(ind);
            }
            sort(tans.begin(),tans.end());
            sort(places.begin(),places.end());
            int m=places.size();
            for(int i=0;i<m;i++){
                ans[places[i]]=tans[i];
            }
        }
        return ans;
    }
};