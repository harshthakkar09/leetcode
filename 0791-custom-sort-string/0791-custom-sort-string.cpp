class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        string s1 = "", s2 = "";
        for(auto c : order){
            freq[c - 'a']++;
        }
        for(auto c : s){
            if(freq[c - 'a'] == 0){
                s2 += c;
            }
            else{
                freq[c - 'a']++;
            }
        }
        for(auto c : order){
            while(freq[c - 'a'] > 1){
                s1 += c;
                freq[c - 'a']--;
            }
        }
        return s1 + s2;
    }
};