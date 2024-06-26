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
    
    void fillArr(TreeNode* root, vector<TreeNode*>& arr){
        if(root == NULL){
            return;
        }
        
        fillArr(root -> left, arr);
        arr.push_back(root);
        fillArr(root -> right, arr);
    }
    
    TreeNode* helper(vector<TreeNode*>& arr, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        root -> left = helper(arr, start, mid - 1);
        root -> right = helper(arr, mid + 1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        fillArr(root, arr);
        int n = arr.size();
        return helper(arr, 0, n - 1);
    }
};