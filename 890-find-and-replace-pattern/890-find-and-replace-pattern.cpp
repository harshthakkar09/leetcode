class Solution {
public:
    
    bool patternMatch(string& s, string& p){
        unordered_map<char,char> track, reverse_track;
        int n = s.size(), m = p.size();
        if(n != m){
            return false;
        }
        for(int i = 0; i < n; i++){
            if(track.find(s[i]) == track.end() && reverse_track.find(p[i]) == reverse_track.end()){
                track[s[i]] = p[i];
                reverse_track[p[i]] = s[i];
            }
            else if(track[s[i]] != p[i] || reverse_track[p[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word: words){
            if(patternMatch(word, pattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};