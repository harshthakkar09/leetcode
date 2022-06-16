typedef long long ll;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>> us;
        for(auto idea:ideas){
            char key=idea[0];
            string value=idea.substr(1,idea.size()-1);
            us[key].insert(value);
        }
        
        ll ans=0;
        
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                unordered_set<string> us1=us['a'+i],us2=us['a'+j];
                int common=0;
                for(auto it:us1){
                    if(us2.find(it)!=us2.end()){
                        common++;
                    }
                }
                ans+=(us1.size()-common)*(us2.size()-common)*2;
            }
        }
        
        return ans;
    }
};