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
    
    int rec(TreeNode* root, int pre){
        if(root == NULL){
            return 0;
        }
        
        if(pre <= root->val){
            return 1 + rec(root->left, root->val) + rec(root->right, root->val);
        }
        else{
            return rec(root->left, pre) + rec(root->right, pre);
        }
    }
    
    int goodNodes(TreeNode* root) {
        return rec(root, INT_MIN);
    }
};