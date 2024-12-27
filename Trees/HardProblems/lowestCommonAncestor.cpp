#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the Lowest Common Ancestor of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is NULL, or root is equal to either p or q, return root
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        // Recursively search for LCA in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are not NULL, root is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }
        
        // If only one side is not NULL, return the non-NULL side
        return (left != NULL) ? left : right;
    }
};

// Helper function to insert a node in a binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Helper function to search for a node in the binary tree
TreeNode* searchNode(TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return searchNode(root->left, val);
    }
    return searchNode(root->right, val);
}

// Main function
int main() {
    Solution solution;

    // Create a sample binary tree
    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
            / \
           3   5
    */
    TreeNode* root = NULL;
    root = insertNode(root, 6);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 0);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 3);
    insertNode(root, 5);

    // Nodes to find the LCA of
    TreeNode* p = searchNode(root, 2);
    TreeNode* q = searchNode(root, 8);

    // Find and print the LCA
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        cout << "The Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
