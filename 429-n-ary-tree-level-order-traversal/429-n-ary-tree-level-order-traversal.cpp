/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> tans;
            while(n--){
                Node* front = q.front();
                q.pop();
                tans.push_back(front->val);
                for(auto child: front->children){
                    q.push(child);
                }
            }
            ans.push_back(tans);
        }
        return ans;
    }
};