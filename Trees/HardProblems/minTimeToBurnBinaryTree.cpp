#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to mark parent nodes and find the target node
Node* markParent(Node* root, unordered_map<Node*, Node*>& mpp, int target) {
    queue<Node*> q;
    Node* res = nullptr;

    // BFS traversal to mark parent nodes and locate the target node
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        // Check if the current node is the target node
        if (node->data == target) res = node;

        // Add left child to the map and queue
        if (node->left) {
            mpp[node->left] = node; // Mark parent
            q.push(node->left);
        }

        // Add right child to the map and queue
        if (node->right) {
            mpp[node->right] = node; // Mark parent
            q.push(node->right);
        }
    }
    return res; // Return the target node
}

// Function to calculate the time required to burn the tree
int findTime(Node* target, unordered_map<Node*, Node*> mpp) {
    queue<Node*> q;
    q.push(target); // Start BFS from the target node
    unordered_map<Node*, bool> visited; // Track visited nodes
    visited[target] = true;
    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        int flag = 0; // To check if any new node is burned in this iteration

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            // Visit the left child
            if (node->left && !visited[node->left]) {
                flag = 1;
                visited[node->left] = true;
                q.push(node->left);
            }

            // Visit the right child
            if (node->right && !visited[node->right]) {
                flag = 1;
                visited[node->right] = true;
                q.push(node->right);
            }

            // Visit the parent
            if (mpp[node] && !visited[mpp[node]]) {
                flag = 1;
                visited[mpp[node]] = true;
                q.push(mpp[node]);
            }
        }

        // If any new nodes are burned, increment the time
        if (flag) time++;
    }

    return time; // Return the total time required to burn the tree
}

// Main function to calculate the minimum time to burn the tree
int minTime(Node* root, int num) {
    unordered_map<Node*, Node*> mpp; // Map to store parent-child relationships
    Node* target = markParent(root, mpp, num); // Locate the target node and mark parents
    int time = findTime(target, mpp); // Calculate the burn time
    return time; // Return the result
}

int main() {
    // Example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int targetValue = 5;
    int time = minTime(root, targetValue);
    cout << "Minimum time to burn the tree from target node " << targetValue << " is: " << time << endl;

    return 0;
}
