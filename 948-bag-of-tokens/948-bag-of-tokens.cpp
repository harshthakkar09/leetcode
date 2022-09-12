class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), l = 0, h = n - 1, ans = 0, score = 0;
        while(l <= h && (tokens[l] <= power || score > 0)){
            while(l <= h && tokens[l] <= power){
                power -= tokens[l];
                l++;
                score++;
            }
            ans = max(ans, score);
            if(score > 0){
                power += tokens[h];
                h--;
                score--;
            }
        }
        return ans;
    }
};