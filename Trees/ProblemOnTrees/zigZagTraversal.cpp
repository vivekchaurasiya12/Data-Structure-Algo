#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node data and set children to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform zigzag level order traversal
vector<vector<int>> zigZagTraversal(Node* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();              // Number of nodes at the current level
        vector<int> row(size);            // Vector to store nodes at the current level

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            // Compute the index for zigzag order
            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = node->data;

            // Push children into the queue
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        leftToRight = !leftToRight;       // Toggle the direction
        result.push_back(row);            // Add the current level to the result
    }
    return result;
}

int main() {
    // Construct a binary tree
    Node* root = new Node(1);            // Root node
    root->left = new Node(2);            // Left child of root
    root->right = new Node(3);           // Right child of root
    root->left->left = new Node(4);      // Left child of node 2
    root->left->right = new Node(5);     // Right child of node 2
    root->right->left = new Node(6);     // Left child of node 3
    root->right->right = new Node(7);    // Right child of node 3
    root->right->left->right = new Node(12); // Right child of node 6

    // Get the zigzag traversal result
    vector<vector<int>> result = zigZagTraversal(root);

    // Print the zigzag traversal
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl; // Newline after each level
    }

    return 0;
}
