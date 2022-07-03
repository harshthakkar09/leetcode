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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* topNode=st1.top();
            st1.pop();
            st2.push(topNode);
            if(topNode->left!=NULL){
                st1.push(topNode->left);
            }
            if(topNode->right!=NULL){
                st1.push(topNode->right);
            }
        }
        while(!st2.empty()){
            TreeNode* topNode=st2.top();
            st2.pop();
            ans.push_back(topNode->val);
        }
        return ans;
    }
};