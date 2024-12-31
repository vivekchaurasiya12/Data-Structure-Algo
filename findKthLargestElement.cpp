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

// Helper function to perform reverse in-order traversal and find the k-th largest element
void findKthLargest(TreeNode* root, int &count, int &ans, int k) {
    if (root == NULL) return; // Base case: if the node is null, return

    // Traverse the right subtree first (larger elements)
    findKthLargest(root->right, count, ans, k);

    // Increment the count of visited nodes
    count++;
    if (count == k) {
        // If count matches k, store the value of the current node as the answer
        ans = root->val;
        return;
    }

    // Traverse the left subtree (smaller elements)
    findKthLargest(root->left, count, ans, k);
}

// Function to find the k-th largest element in the BST
int kthLargest(TreeNode* root, int k) {
    int count = 0; // Counter to keep track of the number of visited nodes
    int ans = -1;  // Variable to store the k-th largest element
    findKthLargest(root, count, ans, k);
    return ans;    // Return the k-th largest element
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

    // Find the k-th largest element
    int k = 3;
    int result = kthLargest(root, k);
    cout << "The " << k << "-th largest element in the BST is: " << result << endl;

    return 0;
}
