#include<bits/stdc++.h>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the ceiling value in a BST for a given key
int findCeil(Node* root, int key) {
    int ceil = -1;  // Initialize the ceil value as -1 (if no ceil exists)
    
    while (root) {  // Traverse the tree
        if (root->data == key) { 
            // If the key is found in the tree, it is the ceiling
            ceil = root->data;
            return ceil;
        }
        if (root->data < key) { 
            // Move to the right subtree if the current node's value is less than the key
            root = root->right;
        } else { 
            // Update the ceil value and move to the left subtree
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;  // Return the final ceil value
}

int main() {
    // Create the BST
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    // Test the findCeil function with a key
    int num = findCeil(root, 9); // Find the ceil for the key 9
    cout << num << endl;        // Output the result
    return 0;
}
