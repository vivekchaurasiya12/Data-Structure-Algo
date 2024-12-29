#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to recursively build the tree.
TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                          vector<int>& inorder, int inStart, int inEnd, 
                          map<int, int>& inMap) {
    // Base case: If the start index exceeds the end index, return NULL.
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    // The first element in the current preorder range is the root node.
    TreeNode* root = new TreeNode(preorder[preStart]);

    // Find the index of the root node in the inorder traversal.
    int inRoot = inMap[root->val];

    // Number of nodes in the left subtree.
    int leftNodes = inRoot - inStart;

    // Recursively build the left subtree.
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftNodes, 
                                 inorder, inStart, inRoot - 1, inMap);

    // Recursively build the right subtree.
    root->right = buildTreeHelper(preorder, preStart + leftNodes + 1, preEnd, 
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// Main function to construct the binary tree.
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // Map to store the index of each value in the inorder traversal for quick lookup.
    map<int, int> inMap;

    // Populate the map with values and their indices from the inorder traversal.
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    // Call the helper function to construct the tree.
    return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                           inorder, 0, inorder.size() - 1, inMap);
}

// Function to print the tree in inorder fashion for verification.
void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main driver function.
int main() {
    // Example input for preorder and inorder traversals.
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the tree.
    TreeNode* root = buildTree(preorder, inorder);

    // Print the tree in inorder to verify correctness.
    cout << "Inorder Traversal of Constructed Tree: ";
    printInOrder(root);

    return 0;
}
