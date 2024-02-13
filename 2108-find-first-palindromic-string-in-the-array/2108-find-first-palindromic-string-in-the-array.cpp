class Solution {
public:
    
    bool checkPalindrome(string& s){
        // cout<<"s "<<s<<"\n";
        int i = 0, j = s.size() - 1;
        while(i <= j){
            // cout<<s[i]<<" "<<s[j]<<"\n";
            if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto word : words){
            if(checkPalindrome(word)){
                return word;
            }
        }
        return "";
    }
};