class Solution {
public:

    int helper(int n, int k){
        if(n == 1){
            return 0;
        }

        int noOfElements = pow(2, (n - 1)), halfElements = noOfElements / 2;

        if(k > halfElements){
            return 1 - helper(n, k - halfElements);
        }

        return helper(n - 1, k);
    }

    int kthGrammar(int n, int k) {
        return helper(n, k);
    }
};