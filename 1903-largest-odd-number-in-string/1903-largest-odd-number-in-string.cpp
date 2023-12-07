class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), rightIndex = -1;
        string ans = "";
        for(int i = n - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                rightIndex = i;
                break;
            }
        }
        if(rightIndex == -1){
            return ans;
        }
        ans = num.substr(0, rightIndex + 1);
        return ans;
    }
};