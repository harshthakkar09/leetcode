class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        vector<int> leftTrack(n);
        vector<int> rightTrack(n);
        unordered_set<char> vis;
        for(int i=0;i<n;i++){
            vis.insert(s[i]);
            leftTrack[i]=vis.size();
        }
        vis.clear();
        for(int i=n-1;i>=0;i--){
            vis.insert(s[i]);
            rightTrack[i]=vis.size();
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(leftTrack[i]==rightTrack[i+1]){
                ans++;
            }
        }
        return ans;
    }
};