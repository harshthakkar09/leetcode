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
typedef long long ll;
class Solution {
public:
    
    bool rec(TreeNode* root,ll mi,ll ma){
        if(root==NULL){
            return true;
        }
        
        if(root->val<=mi || root->val>=ma){
            return false;
        }
        
        return rec(root->left,mi,root->val) && rec(root->right,root->val,ma);
    }
    
    bool isValidBST(TreeNode* root) {
        return rec(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }
};