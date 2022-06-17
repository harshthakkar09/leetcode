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
    
    bool equalTree(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2==NULL){
            return true;
        }
        
        if(r1==NULL || r2==NULL){
            return false;
        }
        
        return r1->val==r2->val && equalTree(r1->left,r2->left) && equalTree(r1->right,r2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        
        if(root==NULL){
            return false;
        }
        
        if(equalTree(root,subRoot)){
            return true;
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};