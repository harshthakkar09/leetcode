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

    void helper(TreeNode* root, map<int, int>& freq){
        if(root == NULL){
            return;
        }

        freq[root -> val]++;
        helper(root -> left, freq);
        helper(root -> right, freq);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> freq;
        helper(root, freq);
        int maxfreq = 0;
        for(auto it : freq){
            maxfreq = max(it.second, maxfreq);
        }
        vector<int> ans;
        for(auto it : freq){
            if(it.second == maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};