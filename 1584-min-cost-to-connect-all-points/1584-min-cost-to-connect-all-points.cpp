class Solution {
public:
    int root(int n,int par[]){
        if(n==par[n]){
            return n;
        }
        return root(par[n],par);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> v;
        int n=points.size();
        int par[n];
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                v.push_back(make_pair(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),make_pair(i,j)));
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            int weight=v[i].first;
            int x=v[i].second.first;
            int y=v[i].second.second;
            int px=root(x,par);
            int py=root(y,par);
            if(px==py){
                continue;
            }
            else{
                ans+=weight;
                par[py]=px;
            }
        }
        return ans;
    }
};