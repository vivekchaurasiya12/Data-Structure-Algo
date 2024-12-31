#include <bits/stdc++.h>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;           // Value of the node
    TreeNode* left;    // Pointer to the left child
    TreeNode* right;   // Pointer to the right child

    // Constructor to initialize a node with a value
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Helper function to check if the tree is a valid BST
bool checkBST(TreeNode* root, long mini, long maxi) {
    if (root == NULL) return true; // An empty tree is a valid BST

    // Check if the current node's value violates the BST property
    if (root->val >= maxi || root->val <= mini) return false;

    // Recursively check the left and right subtrees
    return checkBST(root->left, mini, root->val) && 
           checkBST(root->right, root->val, maxi);
}

// Main function to check if a tree is a valid BST
bool isValidBST(TreeNode* root) {
    // Use long values for min and max to handle edge cases with INT_MIN and INT_MAX
    return checkBST(root, LONG_MIN, LONG_MAX);
}

// Function to test the implementation
int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Check if the tree is a valid BST
    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
