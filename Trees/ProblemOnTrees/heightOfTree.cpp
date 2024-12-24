#include<bits/stdc++.h> 
using namespace std;

// Structure definition for a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value and set left and right pointers to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of a binary tree (Recursive approach)
int maxHeight(Node* root) {
    // Base case: If the node is null, height is 0
    if (root == NULL) return 0;

    // Recursively calculate the height of the left and right subtrees
    int left = maxHeight(root->left);
    int right = maxHeight(root->right);

    // Return the height of the current node as 1 + max(left, right)
    return 1 + max(left, right);
}

// Function to calculate the depth of a binary tree (Iterative approach using level-order traversal)
int maxDepth(Node* root) {
    // Base case: If the root is null, depth is 0
    if (root == NULL) return 0;

    // Initialize a queue to perform level-order traversal
    queue<Node*> q;
    q.push(root); // Start with the root node
    int depth = 0;

    // Traverse the tree level by level
    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        depth++;             // Increment depth for each level

        // Process all nodes at the current level
        for (int i = 0; i < size; i++) {
            Node* temp = q.front(); // Get the front node from the queue
            q.pop();                // Remove it from the queue

            // Add the left child to the queue if it exists
            if (temp->left != NULL) q.push(temp->left);

            // Add the right child to the queue if it exists
            if (temp->right != NULL) q.push(temp->right);
        }
    }

    // Return the depth of the tree
    return depth;
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);         // Root node
    root->left = new Node(2);         // Left child of root
    root->right = new Node(3);        // Right child of root
    root->left->left = new Node(4);   // Left child of node 2
    root->left->right = new Node(5);  // Right child of node 2
    root->right->left = new Node(6);  // Left child of node 3
    root->right->right = new Node(7); // Right child of node 3
    root->right->left->right = new Node(12); // Right child of node 6

    // Calculate height using the recursive approach
    int height = maxHeight(root);

    // Calculate depth using the iterative approach
    int depth = maxDepth(root);

    // Print the results
    cout << "Height (Recursive): " << height << endl;
    cout << "Depth (Iterative): " << depth << endl;

    return 0; 
}
