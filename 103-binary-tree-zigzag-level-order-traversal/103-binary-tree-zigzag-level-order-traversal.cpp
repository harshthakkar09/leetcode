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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> tans;
            while(n--){
                TreeNode* f=q.front();
                q.pop();
                tans.push_back(f->val);
                if(f->right!=NULL){
                    q.push(f->right);
                }
                if(f->left!=NULL){
                    q.push(f->left);
                }
            }
            ans.push_back(tans);
        }
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};