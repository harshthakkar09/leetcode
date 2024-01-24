/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans = 0;
    
    bool check(vector<int> fre){
        int count = 0;
        for(int i = 0; i <= 9; i++){
            if((fre[i] % 2) == 1){
                count++;
                if(count > 1){
                    return false;
                }
            }
        }
        return true;
    }
    
    void helper(TreeNode* root, vector<int>& fre){
        if(root -> left == NULL && root -> right == NULL){
            if(check(fre)){
                ans++;
            }
            return;
        }
        
        if(root -> left){
            int leftVal = root -> left -> val;
            fre[leftVal]++;
            helper(root -> left, fre);
            fre[leftVal]--;
        }
        
        
        if(root -> right){
            int rightVal = root -> right -> val;
            fre[rightVal]++;
            helper(root -> right, fre);
            fre[rightVal]--;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> fre(10, 0);
        fre[root -> val]++;
        helper(root, fre);
        return ans;
    }
};