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
    int ans=0;
    
    pair<int,int> rec(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        
        auto left=rec(root->left);
        int left_sum=left.first;
        int left_num=left.second;
        
        
        auto right=rec(root->right);
        int right_sum=right.first;
        int right_num=right.second;
        
        
        int sum=left_sum+right_sum+root->val;
        int num=left_num+right_num+1;
        
        if((sum/num)==root->val){
            ans++;
        }
        
        return {sum,num};
    }
    
    int averageOfSubtree(TreeNode* root) {
        rec(root);
        return ans;
    }
};