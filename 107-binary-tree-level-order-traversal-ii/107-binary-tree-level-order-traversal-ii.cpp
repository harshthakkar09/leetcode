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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> tans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> tans;
            while(n--){
                TreeNode* front=q.front();
                tans.push_back(front->val);
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }    
            }
            ans.push_back(tans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};