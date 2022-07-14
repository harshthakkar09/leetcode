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
    
    TreeNode* rec(vector<int>& p, vector<int>& i,unordered_map<int,int>& track,int l1,int r1,int l2,int r2){
    
        if(l1>r1 || l2>r2){
            return NULL;
        }
        
        int root_val=p[l1];
        TreeNode* root=new TreeNode(root_val);
        int root_ind=track[root_val];
        int ls=root_ind-l2;
        
        root->left=rec(p,i,track,l1+1,l1+ls,l2,root_ind-1);
        root->right=rec(p,i,track,l1+ls+1,r1,root_ind+1,r2);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> track;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            track[inorder[i]]=i;
        }
        return rec(preorder,inorder,track,0,n-1,0,n-1);
    }
};