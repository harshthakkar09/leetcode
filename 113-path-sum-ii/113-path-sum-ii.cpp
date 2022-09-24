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
    vector<vector<int>> ans;
    
    void rec(TreeNode* root, vector<int>& tans, int target){
        if(root == NULL){
            return;
        }
        
        tans.push_back(root->val);
        if(root->left == NULL && root->right == NULL && target == root->val){
            ans.push_back(tans);
        }
        rec(root->left, tans, target - root->val);
        rec(root->right, tans, target - root->val);
        tans.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tans;
        rec(root, tans, targetSum);
        return ans;
    }
};