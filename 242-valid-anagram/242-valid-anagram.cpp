class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> ms;
        map<char,int> mt;
        for(auto it:s){
            ms[it]++;
        }
        for(auto it:t){
            mt[it]++;
        }
        if(ms==mt){
            return true;
        }
        else{
            return false;
        }
    }
};