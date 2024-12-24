#include<bits/stdc++.h>
using namespace std;

// Definition of the Node structure for a binary tree.
struct Node {
    int data;       // Value stored in the node.
    Node* left;     // Pointer to the left child node.
    Node* right;    // Pointer to the right child node.

    // Constructor to initialize a node with a value and set children to null.
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if two binary trees are identical.
bool isSameTree(Node* root1, Node* root2) {
    // Base case: If either node is null, check if both are null.
    if (root1 == NULL || root2 == NULL) {
        return root1 == root2; // True if both are null, false otherwise.
    }

    // Check the following:
    // 1. The current nodes' data are equal.
    // 2. The left subtrees are identical.
    // 3. The right subtrees are identical.
    return (root1->data == root2->data) 
        && isSameTree(root1->left, root2->left) 
        && isSameTree(root1->right, root2->right);
}

int main() {
    // Construct the first binary tree.
    Node* root1 = new Node(1);         // Root node
    root1->left = new Node(2);         // Left child of root
    root1->right = new Node(3);        // Right child of root
    root1->left->left = new Node(4);   // Left child of node 2
    root1->left->right = new Node(5);  // Right child of node 2
    root1->right->left = new Node(6);  // Left child of node 3
    root1->right->right = new Node(7); // Right child of node 3
    root1->right->left->right = new Node(12); // Right child of node 6

    // Construct the second binary tree.
    Node* root2 = new Node(1);         // Root node
    root2->left = new Node(2);         // Left child of root
    root2->right = new Node(3);        // Right child of root
    root2->left->left = new Node(4);   // Left child of node 2
    root2->left->right = new Node(5);  // Right child of node 2
    root2->right->left = new Node(6);  // Left child of node 3
    root2->right->right = new Node(7); // Right child of node 3
    root2->right->left->right = new Node(12); // Right child of node 6

    // Check if the two trees are identical and print the result.
    if (isSameTree(root1, root2)) {
        cout << "Same Tree";
    } else {
        cout << "Different Tree";
    }

    return 0; 
}
