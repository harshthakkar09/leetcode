class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> um;
        int i = 0, j = 0, n = s.size(), ans = -1;
        while(i < n && j < n){
            if(s[i] == s[j]){
                j++;
            }
            else{
                um[s[i]].push_back(j - i);
                i = j;
            }
        }
        um[s[i]].push_back(j - i);
        for(auto it : um){
            vector<int> v = it.second;
            sort(v.begin(), v.end(), greater<int>());
            int m = v.size();
            if(m < 3){
                while(v.size() != 3){
                    v.push_back(0);
                }
            }
            if(v[0] == v[1] && v[1] == v[2]){
                ans = max(ans, v[0]);
            }
            else if(v[0] == v[1] && v[1] != v[2]){
                ans = max(ans, v[0] - 1 > 0 ? v[0] - 1 : -1);
            }
            else{
                if(v[0] - v[1] > 2){
                    ans = max(ans, v[0] - 2 > 0 ? v[0] - 2 : -1);
                }
                else{
                    ans = max(ans, v[1] > 0 ? v[1] : -1);
                }
            }
        }
        return ans;
    }
};