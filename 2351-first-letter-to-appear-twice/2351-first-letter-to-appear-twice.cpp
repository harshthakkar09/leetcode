class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        unordered_set<char> us;
        for(int i = 0; i < n; i++){
            if(us.find(s[i]) == us.end()){
                us.insert(s[i]);
            }
            else{
                return s[i];
            }
        }
        return 'a';
    }
};