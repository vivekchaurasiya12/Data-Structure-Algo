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

// Helper function to find the rightmost (last) child in a subtree
TreeNode* findLastChild(TreeNode* root) {
    if (root->right == NULL) {
        return root; // Return the node if it's the rightmost
    }
    return findLastChild(root->right); // Recursively traverse to the rightmost child
}

// Helper function to handle node deletion and reorganize the BST
TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) {
        // If there is no left subtree, return the right subtree
        return root->right;
    } else if (root->right == NULL) {
        // If there is no right subtree, return the left subtree
        return root->left;
    }

    // Both left and right subtrees exist
    TreeNode* leftSubtree = root->right;             // Store the right subtree
    TreeNode* lastChild = findLastChild(root->left); // Find the rightmost child in the left subtree
    lastChild->right = leftSubtree;                 // Attach the right subtree to the rightmost child of the left subtree
    return root->left;                              // Return the left subtree as the new root
}

// Function to delete a node with a given key from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL; // Base case: if the tree is empty

    if (root->val == key) {
        // If the root node matches the key, call the helper to delete it
        return helper(root);
    }

    TreeNode* temp = root; // Temporary pointer to traverse the tree
    while (root) {
        if (root->val > key) {
            // Move to the left subtree if the key is smaller
            if (root->left != NULL && root->left->val == key) {
                // If the left child matches the key, delete it using the helper
                root->left = helper(root->left);
                break;
            } else {
                root = root->left; // Continue traversing
            }
        } else {
            // Move to the right subtree if the key is larger
            if (root->right != NULL && root->right->val == key) {
                // If the right child matches the key, delete it using the helper
                root->right = helper(root->right);
                break;
            } else {
                root = root->right; // Continue traversing
            }
        }
    }
    return temp; // Return the updated root of the BST
}

// Function to perform in-order traversal (for testing purposes)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Main function
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    cout << "Original BST (in-order): ";
    inorderTraversal(root);
    cout << endl;

    // Delete a node with a given key
    int key = 5;
    root = deleteNode(root, key);

    cout << "BST after deleting " << key << " (in-order): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
