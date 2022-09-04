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
    
    void rec(TreeNode* root, int height, int width, map<int, vector<pair<int, int>>>& m){
        if(root == NULL){
            return;
        }
        
        m[width].push_back({height, root->val});
        
        if(root->left != NULL){
            rec(root->left, height + 1, width - 1, m);
        }
        
        if(root->right != NULL){
            rec(root->right, height + 1, width + 1, m);
        }
    }
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.first < b.first){
            return true;
        }
        else if(a.first == b.first){
            if(a.second < b.second){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        rec(root, 0, 0, m);
        vector<vector<int>> ans;
        for(auto it: m){
            vector<int> tans;
            sort(it.second.begin(), it.second.end(), cmp);
            for(auto el: it.second){
                tans.push_back(el.second);
            }
            ans.push_back(tans);
        }
        return ans;
    }
};