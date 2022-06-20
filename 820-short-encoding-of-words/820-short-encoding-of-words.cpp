class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        unordered_set<string> us;
        for(auto word:words){
            us.insert(word);
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<words[i].size();j++){
                us.erase(words[i].substr(j));
            }
        }
        int ans=0;
        for(auto i:us){
            ans+=i.size()+1;
        }
        return ans;
    }
};