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
    
    void helper(int sum, TreeNode* root){
        int value = root -> val;
        if(root -> left == NULL && root -> right == NULL){
            ans += (sum * 10) + value;
            return;
        }
        
        if(root -> left != NULL){
            helper(sum * 10 + value, root -> left);
        }
        
        if(root -> right != NULL){
            helper(sum * 10 + value, root -> right);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        helper(0, root);
        return ans;
    }
};