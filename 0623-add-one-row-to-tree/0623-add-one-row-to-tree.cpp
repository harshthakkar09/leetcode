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
    
    void helper(TreeNode* root, int curDepth, int val, int depth){
        
        if(root == NULL){
            return;
        }
        
        if((curDepth + 1) == depth){
            TreeNode* leftNode = root -> left;
            TreeNode* rightNode = root -> right;
            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);
            root -> left -> left = leftNode;
            root -> right -> right = rightNode;
            return;
        }
        
        helper(root -> left, curDepth + 1, val, depth);
        helper(root -> right, curDepth + 1, val, depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        helper(root, 1, val, depth);
        
        return root;
    }
};