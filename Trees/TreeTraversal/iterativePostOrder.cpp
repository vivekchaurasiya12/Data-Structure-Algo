#include <bits/stdc++.h> // Includes all standard headers in C++ (not recommended for production, use specific headers instead)
using namespace std;

// Structure definition for a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value and set left and right pointers to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform post-order traversal of the binary tree
vector<int> postOrderTraversal(Node* root) {
    vector<int> temp; // Vector to store traversal results
    if (root == NULL) {
        return temp;  // If the root is null, return an empty vector
    }

    stack<Node*> st1, st2;  // Two stacks for iterative traversal
    st1.push(root);         // Start with the root node

    while (!st1.empty()) {
        Node* current = st1.top(); // Get the top node from stack 1
        st1.pop();                 // Remove it from stack 1
        st2.push(current);         // Push it onto stack 2

        // Push the left child first (if it exists)
        if (current->left != NULL) {
            st1.push(current->left);
        }

        // Push the right child next (if it exists)
        if (current->right != NULL) {
            st1.push(current->right);
        }
    }

    // Stack 2 will have the nodes in reverse post-order
    while (!st2.empty()) {
        temp.push_back(st2.top()->data); // Add the data to the result vector
        st2.pop();
    }

    return temp; // Return the result vector
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform post-order traversal
    vector<int> result = postOrderTraversal(root);

    // Print the traversal result
    for (const auto& it : result) {
        cout << it << " ";
    }

    return 0;
}
