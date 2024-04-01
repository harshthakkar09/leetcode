class Solution {
public:
    int lengthOfLastWord(string s) {
        string current = "", last;
        for(auto c : s){
            if(c == ' '){
                if(current != ""){
                    last = current;
                    current = "";
                }
            }
            else{
                current += c;
            }
        }
        if(current != ""){
            last = current;
            current = "";
        }
        return last.size();
    }
};