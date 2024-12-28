#include<bits/stdc++.h>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to calculate the height of the leftmost path
int findLeftHeight(TreeNode* node) {
    int height = 0; // Initialize the height counter
    while (node) { // Traverse the leftmost path
        height++; // Increment the height counter
        node = node->left; // Move to the left child
    }
    return height; // Return the height of the leftmost path
}

// Helper function to calculate the height of the rightmost path
int findRightHeight(TreeNode* node) {
    int height = 0; // Initialize the height counter
    while (node) { // Traverse the rightmost path
        height++; // Increment the height counter
        node = node->right; // Move to the right child
    }
    return height; // Return the height of the rightmost path
}

// Function to count the total number of nodes in a binary tree
int countNodes(TreeNode* root) {
    if (root == NULL) return 0; // Base case: If the tree is empty, return 0

    // Calculate the height of the leftmost and rightmost paths
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    // If the left and right heights are the same, the tree is a perfect binary tree
    if (lh == rh) {
        return (1 << lh) - 1; // Total nodes in a perfect binary tree is (2^height - 1)
    }

    // If the tree is not perfect, recursively count nodes in left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Example usage: Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Counting the number of nodes in the binary tree
    int totalNodes = countNodes(root);

    // Printing the result
    cout << "Total number of nodes in the binary tree: " << totalNodes << endl;

    return 0;
}
