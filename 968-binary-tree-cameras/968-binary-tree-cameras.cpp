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
    
    int rec(TreeNode* cur){
        if(cur==NULL){
            return 1;
        }
        
        int l=rec(cur->left);
        int r=rec(cur->right);
        if(l==-1 || r==-1){
            ans++;
            return 0;
        }
        
        if(l==0 || r==0){
            return 1;
        }
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        if(rec(root)==-1){
            ans++;
        }
        return ans;
    }
};