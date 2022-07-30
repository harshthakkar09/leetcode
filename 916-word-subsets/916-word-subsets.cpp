class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> fre(26, 0);
        for(auto subset: words2){
            vector<int> temp_freq(26, 0);
            for(auto c: subset){
                temp_freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                fre[i] = max(temp_freq[i], fre[i]);
            }
        }
        vector<string> ans;
        for(auto word: words1){
            vector<int> temp_fre(26, 0);
            bool flag = false;
            for(auto c: word){
                temp_fre[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(temp_fre[i] < fre[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};