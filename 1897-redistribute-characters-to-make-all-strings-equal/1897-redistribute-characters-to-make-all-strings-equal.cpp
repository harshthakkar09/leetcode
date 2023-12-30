class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        int n = words.size();
        for(auto word : words){
            for(auto c : word){
                freq[c - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            if((freq[i] % n) != 0){
                return false;
            }
        }
        return true;
    }
};