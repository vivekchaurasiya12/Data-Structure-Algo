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

// Function to flatten a binary tree into a "linked list" in place
Node* flattenBinaryTree(Node* root) {
    Node* curr = root; // Start from the root of the tree
    while (curr != NULL) {
        // If the left child exists, find its rightmost node (predecessor)
        if (curr->left != NULL) {
            Node* prev = curr->left; // Move to the left child
            // Find the rightmost node in the left subtree
            while (prev->right != NULL) {
                prev = prev->right;
            }
            // Attach the current node's right subtree to the rightmost node of the left subtree
            prev->right = curr->right;
            // Move the left subtree to the right side
            curr->right = curr->left;
            curr->left = NULL; // Set the left child to NULL
        }
        // Move to the next node (right child)
        curr = curr->right;
    }
    return root; // Return the modified root
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
     root->right->right->left = new Node(7);

    // Flatten the binary tree into a "linked list"
    Node* newRoot = flattenBinaryTree(root);

    // Print the flattened binary tree
    Node* temp = newRoot;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right; // Move to the next node in the "linked list"
    }

    return 0;
}
