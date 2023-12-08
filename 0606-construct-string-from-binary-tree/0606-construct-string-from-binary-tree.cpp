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
    
    string helper(TreeNode* node){
        string leftAns, rightAns;
        if(node -> left == NULL && node -> right == NULL){
            return to_string(node -> val);
        }
        else if(node -> left != NULL && node -> right == NULL){
            leftAns = helper(node -> left);
            return to_string(node -> val) + "(" + leftAns + ")";
        }
        else if(node -> left == NULL && node -> right != NULL){
            rightAns = helper(node -> right);
            return to_string(node -> val) + "()" + "(" + rightAns + ")";
        }
        else{
            leftAns = helper(node -> left);
            rightAns = helper(node -> right);
            return to_string(node -> val) + "(" + leftAns + ")(" + rightAns + ")";
        }
    }
    
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};