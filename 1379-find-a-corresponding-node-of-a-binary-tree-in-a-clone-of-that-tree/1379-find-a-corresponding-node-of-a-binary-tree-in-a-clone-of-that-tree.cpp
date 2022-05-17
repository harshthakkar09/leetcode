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
    TreeNode* getTargetCopy(TreeNode* org, TreeNode* cln, TreeNode* target) {
        TreeNode* ans;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({org,cln});
        while(!q.empty()){
            pair<TreeNode*,TreeNode*> f=q.front();
            q.pop();
            TreeNode* orgf=f.first;
            TreeNode* clnf=f.second;
            if(orgf->val==target->val){
                return clnf;
            }
            if(orgf->left!=NULL){
                q.push({orgf->left,clnf->left});
            }
            if(orgf->right!=NULL){
                q.push({orgf->right,clnf->right});
            }
        }
        return ans;
    }
};