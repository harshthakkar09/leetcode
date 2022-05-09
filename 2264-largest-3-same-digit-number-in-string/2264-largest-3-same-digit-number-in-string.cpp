class Solution {
public:
    
    bool checkAllSame(string s){
        return s[0]==s[1] && s[1]==s[2];
    }
    
    string largestGoodInteger(string num) {
        string ans="";
        int val=-1,n=num.size();
        for(int i=0;i<=n-3;i++){
            string temp_str="";
            for(int j=i;j<i+3;j++){
                temp_str=temp_str+num[j];
            }
            if(checkAllSame(temp_str) && stoi(temp_str)>val){
                ans=temp_str;
                val=stoi(temp_str);
            }
        }
        return ans;
    }
};