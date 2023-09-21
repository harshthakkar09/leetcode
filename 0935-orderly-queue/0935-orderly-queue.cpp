class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string ans = s;
            int n = s.size();
            for(int i = 1; i < n; i++){
                string shuffledString = s.substr(i) + s.substr(0, i);
                if(shuffledString < ans){
                    ans = shuffledString;
                }
            }
            return ans;
        }
        else{
            string ans = s;
            sort(ans.begin(), ans.end());
            return ans;
        }
    }
};