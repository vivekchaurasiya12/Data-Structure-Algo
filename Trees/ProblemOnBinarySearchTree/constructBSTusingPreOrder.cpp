#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Recursive helper function to construct the BST from preorder traversal
TreeNode* build(vector<int>& preorder, int& i, int bound) {
    // Base case: Stop recursion when we reach the end of the preorder vector
    // or the current value exceeds the given boundary
    if (i == preorder.size() || preorder[i] > bound) return NULL;

    // Create a new tree node with the current value from preorder
    TreeNode* root = new TreeNode(preorder[i++]);

    // Recursively build the left subtree
    // The left subtree contains values smaller than the current node's value
    root->left = build(preorder, i, root->val);

    // Recursively build the right subtree
    // The right subtree contains values within the current boundary
    root->right = build(preorder, i, bound);

    // Return the constructed subtree rooted at 'root'
    return root;
}

// Function to construct a BST from its preorder traversal
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0; // Initialize the index to track the current element in preorder
    return build(preorder, i, INT_MAX); // Call the helper function with the maximum boundary
}

// Helper function to print the tree in inorder traversal for verification
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Test the function
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12}; // Preorder traversal of the BST

    // Build the BST from preorder traversal
    TreeNode* root = bstFromPreorder(preorder);

    // Print the inorder traversal of the constructed BST
    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
