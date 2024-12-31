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

// Function to insert a node into the BST
Node* insertNode(Node* root, int val) {
    if (root == NULL) return new Node(val); // If tree is empty, create a new node as root
    Node* curr = root;
    while (curr) {
        if (curr->data <= val) {
            // Move to the right subtree
            if (curr->right != NULL)
                curr = curr->right;
            else {
                curr->right = new Node(val); // Insert the node
                break;
            }
        } else {
            // Move to the left subtree
            if (curr->left != NULL)
                curr = curr->left;
            else {
                curr->left = new Node(val); // Insert the node
                break;
            }
        }
    }
    return root;
}

// Function to display the tree in in-order traversal
void display(Node* root) {
    if (root == NULL) return; // Base case: if node is null, return
    display(root->left);      // Traverse the left subtree
    cout << root->data << " "; // Print the current node
    display(root->right);     // Traverse the right subtree
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

    // Insert a new value into the BST
    Node* newRoot = insertNode(root, 9);

    // Display the updated tree
    cout << "In-order traversal of the updated BST: ";
    display(newRoot);
    cout << endl;

    return 0;
}
