#include<bits/stdc++.h>
using namespace std;

// Structure to represent a node in the binary tree
struct TreeNode{
    int data;              // Data stored in the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize a node with given value and set child pointers to null
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of the tree and check if it's balanced
int dfsheight(TreeNode* root){
    if(root == NULL) return 0; // Base case: null node has height 0

    int left = dfsheight(root->left); // Recursively calculate the height of the left subtree
    if(left == -1) return -1;         // If left subtree is unbalanced, return -1

    int right = dfsheight(root->right); // Recursively calculate the height of the right subtree
    if(right == -1) return -1;          // If right subtree is unbalanced, return -1

    // Check if the current node is unbalanced
    if(abs(left - right) > 1) return -1;

    // Return the height of the current subtree
    return max(left, right) + 1;
}

// Function to check if the binary tree is balanced
bool isBalance(TreeNode* root){
    return dfsheight(root) != -1; // If dfsheight returns -1, tree is unbalanced
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);             // Root node
    root->left = new TreeNode(2);                 // Left child of root
    root->right = new TreeNode(3);                // Right child of root
    root->left->right = new TreeNode(5);          // Right child of node 2
    root->left->left= new TreeNode(8);            // Left child of node 2
    root->left->right->left = new TreeNode(7);    // Left child of node 5
    root->right->left = new TreeNode(6);          // Left child of node 3
    root->left->right->left->right = new TreeNode(11); // Right child of node 7

    // Check if the tree is balanced
    bool check = isBalance(root);
    if(check){
        cout<<"balanced binary tree";  // Output if the tree is balanced
    }else{
        cout<<"unbalanced binary tree"; // Output if the tree is unbalanced
    }
    return 0;
}
