class Solution {
public:
    
    double rec(string up,string down, unordered_map<string,unordered_map<string,double>>& graph,unordered_set<string>& s){
        if(graph[up].find(down)!=graph[up].end()){
            return graph[up][down];
        }
        for(auto i:graph[up]){
            if(s.find(i.first)==s.end()){
                s.insert(i.first);
                double tmp=rec(i.first,down,graph,s);
                if(tmp){
                    return i.second*tmp;
                }
            }
        }
        return 0;
    }
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,unordered_map<string,double>> graph;
        vector<double> ans;
        for(int i=0;i<values.size();i++){
            graph[equations[i][0]].insert(make_pair(equations[i][1],values[i]));
            if(values[i]!=0){
                graph[equations[i][1]].insert(make_pair(equations[i][0],1/values[i]));
            }
        }
        
        for(int i=0;i<queries.size();i++){
            unordered_set<string> s;
            double tmp=rec(queries[i][0],queries[i][1],graph,s);
            if(tmp){
                ans.push_back(tmp);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};