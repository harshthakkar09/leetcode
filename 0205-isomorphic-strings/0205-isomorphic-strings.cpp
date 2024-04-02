class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> rev;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end()){
                if(rev.find(t[i]) == rev.end()){
                    mp[s[i]] = t[i];
                    rev[t[i]] = s[i];
                }
                else if(rev.find(t[i]) != rev.end() && rev[t[i]] != s[i]){
                    return false;
                }
               
            }
            else{
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};