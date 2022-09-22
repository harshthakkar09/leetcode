class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        vector<string> words;
        string word = "", ans = "";
        while(i < n){
            if(s[i] == ' '){
                words.push_back(word);
                word = "";
            }
            else{
                word += s[i];
            }
            i++;
        }
        words.push_back(word);
        int m = words.size();
        for(int i = 0; i < (m - 1); i++){
            reverse(words[i].begin(), words[i].end());
            ans += words[i];
            ans += " ";
        }
        reverse(words[m - 1].begin(), words[m - 1].end());
        ans += words[m - 1];
        return ans;
    }
};