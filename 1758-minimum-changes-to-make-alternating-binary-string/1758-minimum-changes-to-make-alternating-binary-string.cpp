class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;
        bool oneTurn = true;
        for(auto c : s){
            if(oneTurn){
                if(c == '0'){
                    count1++;
                }
            }
            else{
                if(c == '1'){
                    count1++;
                }
            }
            oneTurn = !oneTurn;
        }
        oneTurn = false;
        for(auto c : s){
            if(oneTurn){
                if(c == '0'){
                    count2++;
                }
            }
            else{
                if(c == '1'){
                    count2++;
                }
            }
            oneTurn = !oneTurn;
        }
        return min(count1, count2);
    }
};