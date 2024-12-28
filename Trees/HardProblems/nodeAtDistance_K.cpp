#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
  This is used when address of target node is not given then this traversal helps to find the target node
  
 BFS to find the node with the given target value.
TreeNode* findNode(TreeNode* root, int targetVal) {
    if (root == nullptr) return nullptr;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

         If the current node matches the target value, return it
        if (node->val == targetVal) {
            return node;
        }

         Add the left and right children to the queue
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

     If the target value is not found, return nullptr
    return nullptr;
}
*/

// Function to mark parents of each node in the binary tree
void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q; // Queue for BFS traversal
    q.push(root); // Start with the root node
    while (!q.empty()) {
        TreeNode* node = q.front(); // Get the current node
        q.pop();

        // If the current node has a left child
        if (node->left) {
            parent[node->left] = node; // Mark the current node as the parent of its left child
            q.push(node->left); // Add the left child to the queue
        }

        // If the current node has a right child
        if (node->right) {
            parent[node->right] = node; // Mark the current node as the parent of its right child
            q.push(node->right); // Add the right child to the queue
        }
    }
}

// Function to find all nodes at distance K from the target node
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent; // Map to store parent pointers
    markParent(root, parent); // Mark parents for all nodes in the tree

    queue<TreeNode*> q; // Queue for BFS traversal
    unordered_map<TreeNode*, bool> visited; // Map to track visited nodes
    q.push(target); // Start BFS from the target node
    visited[target] = true; // Mark the target node as visited

    int distance = 0; // Distance from the target node
    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        if (distance == k) break; // Stop when the required distance is reached
        distance++;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); // Get the front node in the queue
            q.pop();

            // Visit the left child
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }

            // Visit the right child
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }

            // Visit the parent of the current node
            if (parent[node] && !visited[parent[node]]) {
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
    }

    // Collect all nodes at the required distance
    vector<int> result;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);
    }

    return result;
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // Target node with value 5
    int k = 2; // Distance from the target node

    // Find all nodes at distance K
    vector<int> result = distanceK(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from target node: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
