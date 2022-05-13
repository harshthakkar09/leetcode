/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* find(Node* root){
        while(root){
            if(root->left){
                return root->left;
            }
            else if(root->right){
                return root->right;
            }
            root=root->next;
        }
        return NULL;
    }
    
    Node* rec(Node* root){
        if(root==NULL){
            return root;
        }
        
        if(root->left){
            if(root->right){
                root->left->next=root->right;
            }
            else{
                root->left->next=find(root->next);
            }
        }
        
        if(root->right){
            root->right->next=find(root->next);
        }
        
        rec(root->right);
        rec(root->left);
        
        return root;
    }
    
    Node* connect(Node* root) {
       return rec(root);
    }
};