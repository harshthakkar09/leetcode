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
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur=root;
        vector<int> ans;
        while(true){
            if(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }
            else{
                if(s.empty()){
                    break;
                }
                ans.push_back(s.top()->val);
                cur=s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};