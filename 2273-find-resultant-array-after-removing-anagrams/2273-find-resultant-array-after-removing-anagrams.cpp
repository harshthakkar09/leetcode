class Solution {
public:
    
    bool checkAnagram(string& s1,string& s2){
        if(s1.size()!=s2.size()){
            return false;
        }
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto c:s1){
            m1[c]++;
        }
        for(auto c:s2){
            m2[c]++;
        }
        return m1==m2;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();){
            if(checkAnagram(words[i],words[i-1])){
                words.erase(words.begin()+i);
            }
            else{
                i++;
            }
        }
        return words;
    }
};