#include <bits/stdc++.h> // Includes all standard headers in C++ (not recommended for production, use specific headers instead)
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;        // Value of the node
    TreeNode* left;  // Pointer to the left child
    TreeNode* right; // Pointer to the right child

    // Constructor to initialize a node with a value and set left and right pointers to nullptr
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform level-order traversal of the binary tree
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans; // Vector to store results level by level
    if (root == NULL) return ans; // Return an empty vector if the tree is empty

    queue<TreeNode*> q; // Queue to store nodes for BFS
    q.push(root);       // Start with the root node

    while (!q.empty()) {
        int size = q.size();      // Number of nodes at the current level
        vector<int> temp;         // Temporary vector to store the current level's values

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); // Get the front node in the queue
            q.pop();                    // Remove the node from the queue

            // Add the node's children to the queue if they exist
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);

            // Add the current node's data to the temp vector
            temp.push_back(node->data);
        }

        // Add the current level's values to the result
        ans.push_back(temp);
    }

    return ans; // Return the final result
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform level-order traversal
    vector<vector<int>> result = levelOrder(root);

    // Print the level-order traversal result
    cout << "Level-Order Traversal: " << endl;
    for (const auto& level : result) {
        for (const auto& val : level) {
            cout << val << " ";
        }
        cout << endl; // Move to the next line for the next level
    }

    return 0;
}

/*
IMPORTANT NOTES:

1. **Tree Node Structure**:
   - The `TreeNode` structure has `data`, `left`, and `right` members to define the binary tree.
   - A constructor initializes the node with a value and sets child pointers to `nullptr`.

2. **Level-Order Traversal**:
   - Level-order traversal uses BFS (Breadth-First Search) to visit nodes level by level.
   - A queue is used to store nodes at the current level and their children for the next level.

3. **Steps in Level-Order Traversal**:
   - Push the root node into the queue.
   - For each level:
     - Process all nodes in the queue (current level).
     - Add their children (next level) to the queue.
   - Store the values of the current level in a temporary vector and add it to the result.

4. **Edge Case**:
   - If the tree is empty (`root == NULL`), an empty vector is returned.

5. **Memory Management**:
   - Dynamically allocated nodes should be properly deallocated in a real-world application to avoid memory leaks.

*/

/*
TIME COMPLEXITY:
- Each node is visited once.
- For a tree with `n` nodes, the time complexity is O(n).

SPACE COMPLEXITY:
- The queue stores nodes at the current level, which can be at most O(w), where `w` is the maximum width of the tree.
- The result vector uses O(n) space to store the traversal results.
- Total space complexity: O(n).

*/

/*
EXAMPLE OUTPUT:
For the binary tree:
        1
       / \
      2   3
     / \ / \
    4  5 6  7

The output will be:
Level-Order Traversal:
1
2 3
4 5 6 7
*/
