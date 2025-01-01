#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;            // Value of the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child

    // Constructor to initialize a node with a value
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the Lowest Common Ancestor (LCA) in a Binary Search Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: If the root is NULL, return NULL (end of tree traversal)
    if (root == NULL) return NULL;

    int curr = root->val; // Current node's value

    // Case 1: Both p and q are greater than the current node
    // Move to the right subtree to find the LCA
    if (curr < p->val && curr < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Case 2: Both p and q are smaller than the current node
    // Move to the left subtree to find the LCA
    if (curr > p->val && curr > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Case 3: Current node is the Lowest Common Ancestor
    // This happens when p and q lie on either side of the current node
    return root;
}

// Test the function
int main() {
    // Create a sample Binary Search Tree (BST)
    /*
                6
               / \
              2   8
             / \ / \
            0  4 7  9
              / \
             3   5
    */
    TreeNode* root = new TreeNode(6); // Root node
    root->left = new TreeNode(2);     // Left child of root
    root->right = new TreeNode(8);    // Right child of root
    root->left->left = new TreeNode(0);  // Left subtree of 2
    root->left->right = new TreeNode(4); // Right subtree of 2
    root->right->left = new TreeNode(7); // Left subtree of 8
    root->right->right = new TreeNode(9); // Right subtree of 8
    root->left->right->left = new TreeNode(3); // Left subtree of 4
    root->left->right->right = new TreeNode(5); // Right subtree of 4

    TreeNode* p = root->left;        // Node with value 2
    TreeNode* q = root->right;       // Node with value 8

    // Find the LCA of nodes p and q
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Output the result
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
