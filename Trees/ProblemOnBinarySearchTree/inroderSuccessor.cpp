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

// Function to find the inorder successor of a node in a BST
Node* inorderSuccessor(Node* root, Node* p) {
    Node* successor = NULL; // Initialize the successor to NULL
    while (root) {          // Traverse the tree until root is NULL
        if (p->val >= root->val) {
            // Move to the right subtree if p->val >= root->val
            root = root->right;
        } else {
            // Update successor and move to the left subtree
            successor = root;
            root = root->left;
        }
    }
    return successor; // Return the successor
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

    // Test the inorderSuccessor function
    Node* p = root->right->left; // Node with value 6
    Node* successor = inorderSuccessor(root, p);

    if (successor) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    return 0;
}
