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
    
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftAns = helper(root ->left), rightAns = helper(root -> right);
        
        ans = max(ans, leftAns + rightAns);
        return 1 + max(leftAns, rightAns);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
    }
};