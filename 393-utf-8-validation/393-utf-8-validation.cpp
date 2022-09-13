class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rem = 0;
        for(auto d: data){
            if(rem == 0){
                if((d >> 3) == 0b11110){
                    rem = 3;
                }
                else if((d >> 4) == 0b1110){
                    rem = 2;
                }
                else if((d >> 5) == 0b110){
                    rem = 1;
                }
                else if((d >> 7) != 0b0){
                    return false;
                }
            }
            else{
                if((d >> 6) != 0b10){
                    return false;
                }
                rem--;
            }
        }
        return rem == 0;
    }
};