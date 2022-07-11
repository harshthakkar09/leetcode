class Solution {
public:
    
    bool check(string& a, string& b){
        if(a.size() != b.size()){
            return false;
        }
        
        int n = a.size(), i = 0, j = 0;
        while(i < n && j < n){
            while(i < n && a[i] == 'X'){
                ++i;
            }
            while(j < n && b[j] == 'X'){
                ++j;
            }
            if(i == n && j == n){
                return true;
            }
            if(a[i] != b[j]){
                return false;
            }
            if(a[i] == 'R' && i > j){
                return false;
            }
            if(a[i] == 'L' && j > i){
                return false;
            }
            ++i;
            ++j;
        }
        while(a[i] == 'X' && i < n){
            ++i;
        }
        while(b[j] == 'X' && j < n){
            ++j;
        }
        return i == j;
    }
    
    bool canTransform(string start, string end) {
        return check(start, end);
    }
};