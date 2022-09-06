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
    
    bool isContainOne(TreeNode* root){
        if(root == NULL){
            return false;
        }
        
        bool leftContainOne = isContainOne(root->left);
        bool rightContainOne = isContainOne(root->right);
        
        if(!leftContainOne){
            root->left = NULL;
        }
        
        if(!rightContainOne){
            root->right = NULL;
        }
        
        return root->val == 1 || leftContainOne || rightContainOne;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(isContainOne(root)){
            return root;
        }
        return NULL;
    }
};