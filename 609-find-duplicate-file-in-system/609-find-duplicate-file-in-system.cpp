class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string, vector<string>> track;
        for(auto path: paths){
            int i = 0, j;
            while(path[i] != ' '){
                i++;
            }
            string dir = path.substr(0, i), file, content;
            while(i < path.size()){
                j = i;
                while(path[i] != '('){
                    i++;
                }
                file = path.substr(j + 1, i - j - 1);
                j = i;
                while(path[i++] != ')'){
                }
                content = path.substr(j, i - j);
                track[content].push_back(dir + "/" + file);
            }
            
        }
        for(auto it: track){
            if(it.second.size() > 1){
                vector<string> tans;
                for(auto file: it.second){
                    tans.push_back(file);
                }
                ans.push_back(tans);
            }
        }
        return ans;
    }
};