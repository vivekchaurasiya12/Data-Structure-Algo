#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform vertical traversal
vector<vector<int>> verticalTraversal(Node* root) {
    // Nested map to store nodes by coordinates
    map<int, map<int, multiset<int>>> nodes;
    
    // Queue for BFS traversal
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        
        Node* node = p.first;
        int x = p.second.first;  // Horizontal distance
        int y = p.second.second; // Vertical level
        
        // Insert the node's value into the map
        nodes[x][y].insert(node->val);
        
        // Push left and right children with updated coordinates
        if (node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }
    
    // Prepare the result
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// Helper function to build the tree (example tree)
    Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// Main function
int main() {
    Node* root = buildTree();
    
    // Perform vertical traversal
    vector<vector<int>> result = verticalTraversal(root);
    
    // Print the result
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
