class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        char pre = '.';
        int time = 1;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                pre = 'R';
                time = 1;
            }
            else if(dominoes[i] == 'L'){
                pre = 'L';
            }
            else if(dominoes[i] == '.' && pre == 'R'){
                right[i] = time;
                time++;
            }
        }
        pre = '.';
        time = 1;
        for(int i = n - 1; i >= 0; i--){
            if(dominoes[i] == 'L'){
                pre = 'L';
                time = 1;
            }
            else if(dominoes[i] == 'R'){
                pre = 'R';
            }
            else if(dominoes[i] == '.' && pre == 'L'){
                left[i] = time;
                time++;
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(left[i] == right[i]){
                ans += dominoes[i];
            }
            else if(left[i] == 0){
                ans += 'R';
            }
            else if(right[i] == 0){
                ans += 'L';
            }
            else if(left[i] == right[i]){
                ans += '.';
            }
            else if(left[i] < right[i]){
                ans += 'L';
            }
            else{
                ans += 'R';
            }
        }
        return ans;
    }
};