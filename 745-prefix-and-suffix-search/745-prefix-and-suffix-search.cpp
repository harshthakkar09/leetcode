class WordFilter {
public:
    unordered_map<string,int> um;
    
    WordFilter(vector<string>& words) {
        int index=0;
        for(auto word:words){
            int n=word.size();
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    string s=word.substr(0,i)+"#"+word.substr(j);
                    um[s]=index;
                }
            }
            index++;
        }
    }
    
    int f(string pre, string suf) {
        string query=pre+"#"+suf;
        if(um.find(query)!=um.end()){
            return um[query];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */