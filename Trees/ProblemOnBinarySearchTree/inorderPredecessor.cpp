#include <bits/stdc++.h>
using namespace std;

// Define the structure of a tree node
struct Node {
    int val;           // Value of the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the inorder predecessor of a node in a BST
Node* inorderPredecessor(Node* root, Node* p) {
    Node* predecessor = NULL; // Initialize the predecessor to NULL
    while (root) {            // Traverse the tree until root is NULL
        if (root->val >= p->val) {
            root = root->left; // Move left if current value is greater or equal to p->val
        } else {
            // Update predecessor and move to the right subtree
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor; // Return the predecessor
}

// Function to test the implementation
int main() {
    // Create a sample tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Test the inorderPredecessor function
    Node* p = root->right->left; // Node with value 6
    Node* predecessor = inorderPredecessor(root, p);

    if (predecessor) {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } else {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }

    return 0;
}
