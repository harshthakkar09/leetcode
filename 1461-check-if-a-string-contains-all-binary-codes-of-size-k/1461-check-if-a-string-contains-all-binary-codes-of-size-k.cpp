class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string> us;
        string temp="";
        for(int i=0;i<n;i++){
            temp+=s[i];
            if(i>=k-1){
                us.insert(temp);
                temp.erase(0,1);
            }
        }
        return us.size()==pow(2,k);
    }
};