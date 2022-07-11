/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lca(TreeNode* cur, TreeNode* p, TreeNode* q){
        if((p->val < cur->val && cur->val < q->val) || (p->val == cur->val || q->val == cur->val)){
            return cur;
        }
        
        if(p->val < cur->val){
            return lca(cur->left, p, q);
        }
        else{
            return lca(cur->right, p, q);
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p, q);
        }
        return lca(root, p, q);
    }
};