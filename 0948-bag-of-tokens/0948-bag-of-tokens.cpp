class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), l = 0, h = n - 1, score = 0, ans = 0;
        while(l <= h){
            // cout<<"l: "<<l<<" h: "<<h<<"\n";
            if(power >= tokens[l]){
                power -= tokens[l];
                l++;
                score++;
                ans = max(ans, score);
                // cout<<"con1 ans "<<ans<<" power "<<power<<" score "<<score<<"\n";
            }
            else if(score > 0){
                score--;
                power += tokens[h];
                h--;
                // cout<<"con2 power "<<power<<" score "<<score<<"\n";
            }
            else{
                break;
            }
        }
        return ans;
    }
};