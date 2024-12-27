#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum width of the binary tree
int maxWidthOfBinaryTree(Node* root) {
    if (root == NULL) return 0;

    // Queue to perform level-order traversal; stores nodes and their indices
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        int minIndex = q.front().second; // To normalize indices at each level
        int firstIndex, lastIndex;

        for (int i = 0; i < size; i++) {
            int currIndex = q.front().second - minIndex; // Normalize index
            Node* node = q.front().first;
            q.pop();

            if (i == 0) firstIndex = currIndex; // Index of the first node at this level
            if (i == size - 1) lastIndex = currIndex; // Index of the last node at this level

            // Push left and right children with their corresponding indices
            if (node->left) q.push({node->left, currIndex * 2 + 1});
            if (node->right) q.push({node->right, currIndex * 2 + 2});
        }

        // Calculate the width of the current level
        maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
    }

    return maxWidth;
}

// Main function
int main() {
    // Construct a binary tree
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculate the maximum width of the binary tree
    int ans = maxWidthOfBinaryTree(root);
    cout << "The maximum width of the binary tree is: " << ans << endl;

    return 0;
}
