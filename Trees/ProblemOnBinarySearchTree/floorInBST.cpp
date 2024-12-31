#include <bits/stdc++.h>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the floor value in a BST for a given key
int findFloor(Node* root, int key) {
    int floor = -1;  // Initialize the floor value as -1 (if no floor exists)
    
    while (root) {  // Traverse the tree
        if (root->data == key) { 
            // If the key is found in the tree, it is the floor
            floor = root->data;
            return floor;
        }
        if (root->data < key) { 
            // Update the floor value and move to the right subtree
            floor = root->data;
            root = root->right;
        } else { 
            // Move to the left subtree if the current node's value is greater than the key
            root = root->left;
        }
    }
    return floor;  // Return the final floor value
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

    // Test the findFloor function with a key
    int num = findFloor(root, 9); // Find the floor for the key 9
    cout << num << endl;          // Output the result
    return 0;
}
