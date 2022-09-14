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
    int count = 0, path;
    
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        path ^= (1 << root->val);
    
        if(root->left == NULL && root->right == NULL){
            if((path & (path - 1)) == 0){
                count++;
            }
        }
        dfs(root->left);
        dfs(root->right);
        path ^= (1 << root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return count;
    }
};