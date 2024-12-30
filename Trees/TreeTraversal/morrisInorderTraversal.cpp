#include <bits/stdc++.h>
using namespace std;

// Define the structure for a Tree Node
struct Node {
    int data;             // Value of the node
    Node* left;           // Pointer to the left child
    Node* right;          // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform Morris Inorder Traversal
// This traversal avoids using stack or recursion
vector<int> morrisInorder(Node* root) {
    vector<int> inorder; // To store the inorder traversal result
    Node* curr = root;   // Pointer to traverse the tree

    while (curr != NULL) {
        // Case 1: If there is no left child
        if (curr->left == NULL) {
            inorder.push_back(curr->data); // Add current node's value to result
            curr = curr->right;           // Move to the right child
        } else {
            // Case 2: Find the rightmost node in the left subtree
            Node* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right; // Move to the rightmost node in the left subtree
            }

            // Case 2a: Create a thread (temporary link) to the current node
            if (prev->right == NULL) {
                prev->right = curr;  // Create a thread to the current node
                curr = curr->left;  // Move to the left child
            } else {
                // Case 2b: If the thread already exists, remove it
                prev->right = NULL;           // Break the thread
                inorder.push_back(curr->data); // Add the current node's value
                curr = curr->right;           // Move to the right child
            }
        }
    }

    return inorder; // Return the inorder traversal result
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    // Perform Morris Inorder Traversal
    vector<int> result = morrisInorder(root);

    // Print the inorder traversal result
    for (auto it : result) {
        cout << it << " ";
    }

    return 0;
}
