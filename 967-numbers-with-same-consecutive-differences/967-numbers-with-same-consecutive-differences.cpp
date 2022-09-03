class Solution {
public:
    
    void rec(int num, int rem, int k, unordered_set<int>& ansSet){
        if(rem == 0){
            ansSet.insert(num);
            return;
        }
        
        int lastDigit = num % 10, newDigit1 = lastDigit + k, newDigit2 = lastDigit - k;
        if(newDigit1 >= 0 && newDigit1 <= 9){
            rec((num * 10) + newDigit1, rem - 1, k, ansSet);
        }
        if(newDigit2 >= 0 && newDigit2 <= 9){
            rec((num * 10) + newDigit2, rem - 1, k, ansSet);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> ansSet;
        for(int i = 1; i <= 9; i++){
            rec(i, n - 1, k, ansSet);
        }
        vector<int> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};