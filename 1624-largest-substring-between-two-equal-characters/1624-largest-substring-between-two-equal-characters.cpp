class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n ; j++){
                if(s[i] == s[j]){
                    ans = max(ans, j - i + 1 - 2);
                }
            }
        }
        return ans;
    }
};