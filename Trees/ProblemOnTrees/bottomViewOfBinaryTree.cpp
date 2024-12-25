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

// Function to compute the top view of the binary tree
vector<int> bottomView(Node* root) {
    vector<int> ans; // Vector to store the result
    if (root == nullptr) return ans;

    map<int, int> mpp; // Map to store the first node at each horizontal distance
    queue<pair<Node*, int>> q; // Queue for level-order traversal
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        // Push left and right children with updated horizontal distances
        if (node->left != nullptr) q.push({node->left, line - 1});
        if (node->right != nullptr) q.push({node->right, line + 1});
    }

    // Extract the top view nodes from the map
    for (auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get the top view of the tree
    vector<int> result = bottomView(root);

    // Print the top view
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
