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
    
    void rec(TreeNode* root, int level, map<int, int>& track){
        
        if(root==NULL){
            return;
        }
        
        if(track.find(level) == track.end()){
            track[level] = root->val;
        }
        
        rec(root->right, level+1, track);
        rec(root->left, level+1, track);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> track;
        rec(root, 0, track);
        vector<int> ans;
        for(auto it:track){
            ans.push_back(it.second);
        }
        return ans;
    }
};