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
    
    TreeNode* findLCA(TreeNode* root, int start, int end){
        if(root == NULL || root->val == start || root->val == end){
            return root;
        }
        
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    
    bool getPath(TreeNode* root, int val, string& s){
        if(root == NULL){
            return false;
        }
        
        if(root->val == val){
            return true;
        }
        
        if(getPath(root->left, val, s)){
            s += 'L';
            return true;
        }
        else if(getPath(root->right, val, s)){
            s += 'R';
            return true;
        }
        else{
            return false;
        }
    }
    
    string processPaths(string& s1, string& s2){
        string ans = "";
        for(auto c: s1){
            ans += 'U';
        }
        reverse(s2.begin(), s2.end());
        ans += s2;
        return ans;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        string path1 = "";
        string path2 = "";
        
        getPath(lca, startValue, path1);
        getPath(lca, destValue, path2);
        
        return processPaths(path1, path2);
    }
};