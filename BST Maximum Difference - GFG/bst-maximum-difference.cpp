//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int getRootTargetSum(Node* root, int target, Node** targetNode){
        
        if(root == NULL){
            return INT_MIN;
        }
        
        if(root -> data == target){
            *targetNode = root;
            return root -> data;
        }
        
        if(target < (root -> data)){
            return root -> data + getRootTargetSum(root -> left, target, targetNode);
        }
        else{
            return root -> data + getRootTargetSum(root -> right, target, targetNode);
        }
    }
    
    int targetToMinSum(Node* cur){
        if(cur == NULL){
            return INT_MAX / 2;
        }
        
        if(cur -> left == NULL && cur -> right == NULL){
            return cur -> data;
        }
        
        int left = targetToMinSum(cur -> left);
        int right = targetToMinSum(cur -> right);
        
        return cur -> data + min(left, right);
    }

    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node* targetNode = NULL;
        int rootTargetSum = getRootTargetSum(root, target, &targetNode);
        
        if(targetNode == NULL){
            return -1;
        }
        
        return rootTargetSum - targetToMinSum(targetNode);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends