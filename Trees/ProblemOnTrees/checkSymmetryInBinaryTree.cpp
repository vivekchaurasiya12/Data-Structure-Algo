#include<bits/stdc++.h>
using namespace std;

// Structure to represent a node in the binary tree
struct Node {
    int data;             // Data stored in the node
    Node* left;           // Pointer to the left child
    Node* right;          // Pointer to the right child
    
    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if two subtrees are mirror images of each other
bool isSymmetric(Node* left, Node* right) {
    // If either subtree is NULL, return true only if both are NULL
    if (left == NULL || right == NULL) return left == right;
    
    // If the values of the nodes do not match, the tree is not symmetric
    if (left->data != right->data) return false;
    
    // Recursively check the symmetry of corresponding child nodes
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

// Function to check if a binary tree is symmetric
bool checkSymmetry(Node* root) {
    // An empty tree is symmetric
    if (root == NULL) return true;
    
    // Check symmetry between the left and right subtrees of the root
    return isSymmetric(root->left, root->right);
}

int main() {
    // Constructing a sample binary tree
    Node* root = new Node(1);               // Root node
    root->left = new Node(2);               // Left child of root
    root->right = new Node(2);              // Right child of root
    root->left->left = new Node(4);         // Left child of node 2
    root->left->right = new Node(5);        // Right child of node 2
    root->right->left = new Node(5);        // Left child of node 3
    root->right->right = new Node(4);       // Right child of node 

    // Check if the tree is symmetric and print the result
    if (checkSymmetry(root)) {
        cout << "tree is symmetric";
    } else {
        cout << "not symmetric";
    }

    return 0;
}
