class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, n = g.size(), m = s.size(), ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < n && j < m){
            if(g[i] <= s[j]){
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};