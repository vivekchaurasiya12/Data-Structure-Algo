#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to recursively construct the binary tree.
TreeNode* makeTree(vector<int>& inorder, int instart, int inend, 
                   vector<int>& postorder, int poststart, int postend, 
                   map<int, int>& inmap) {
    // Base case: If start index exceeds the end index, return NULL.
    if (instart > inend || poststart > postend) {
        return NULL;
    }

    // The last element in the current postorder range is the root node.
    TreeNode* root = new TreeNode(postorder[postend]);

    // Find the index of the root node in the inorder traversal.
    int inroot = inmap[root->val];

    // Number of nodes in the left subtree.
    int numLeft = inroot - instart;

    // Recursively construct the left subtree.
    root->left = makeTree(inorder, instart, inroot - 1, 
                          postorder, poststart, poststart + numLeft - 1, inmap);

    // Recursively construct the right subtree.
    root->right = makeTree(inorder, inroot + 1, inend, 
                           postorder, poststart + numLeft, postend - 1, inmap);

    return root;
}

// Main function to construct the binary tree from inorder and postorder traversals.
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // Map to store the index of each value in the inorder traversal for quick lookup.
    map<int, int> inmap;

    // Populate the map with values and their indices from the inorder traversal.
    for (int i = 0; i < inorder.size(); i++) {
        inmap[inorder[i]] = i;
    }

    // Call the helper function to construct the tree.
    return makeTree(inorder, 0, inorder.size() - 1, 
                    postorder, 0, postorder.size() - 1, inmap);
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
    // Example input for inorder and postorder traversals.
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Build the tree.
    TreeNode* root = buildTree(inorder, postorder);

    // Print the tree in inorder to verify correctness.
    cout << "Inorder Traversal of Constructed Tree: ";
    printInOrder(root);

    return 0;
}
