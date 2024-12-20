#include<bits/stdc++.h> // Includes all standard headers in C++ (not recommended for production, use specific headers instead)
using namespace std;

// Structure definition for a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value and set left and right pointers to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal of the binary tree
vector<int> preOrderTraversal(Node* root) {
    vector<int> temp; // Vector to store traversal results
    if (root == NULL) {
        return temp;  // If the node is null, return an empty vector
    }
    // Visit the current node (root)
    temp.push_back(root->data);

    // Recur for the left subtree
    vector<int> left = preOrderTraversal(root->left);
    
    // Recur for the right subtree
    vector<int> right = preOrderTraversal(root->right);

    // Append left and right subtree results to the current result
    temp.insert(temp.end(), left.begin(), left.end());
    temp.insert(temp.end(), right.begin(), right.end());

    return temp; // Return the combined result
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

    // Perform preorder traversal
    vector<int> result = preOrderTraversal(root);

    // Print the traversal result
    for (const auto& it : result) {
        cout << it << " ";
    }

    return 0;
}

/*
IMPORTANT NOTES:

1. **Tree Node Structure**:
   - Each node has a `data` field and pointers to its left and right children.
   - Constructor initializes node values and sets child pointers to `nullptr`.

2. **Preorder Traversal**:
   - Preorder traversal visits nodes in this order:
     1. Visit the root.
     2. Traverse the left subtree.
     3. Traverse the right subtree.
   - The result vector `temp` collects the nodes' data in this order.

3. **Base Case in Recursion**:
   - If `root` is `NULL`, an empty vector is returned. This ensures the recursion terminates.

4. **Recursive Calls**:
   - Recursion is used to traverse the left and right subtrees.
   - Results from the left and right subtrees are appended to the current node's results using `insert`.

5. **Combining Results**:
   - The `temp` vector combines the root, left subtree, and right subtree in the correct preorder sequence.

6. **Memory Allocation**:
   - Tree nodes are dynamically allocated using `new`. Ensure proper deletion in real-world applications to avoid memory leaks.

*/

/*
TIME COMPLEXITY:
- The function visits each node of the tree exactly once.
- For a tree with `n` nodes, the time complexity is O(n).

SPACE COMPLEXITY:
- The function uses additional space for:
  1. Recursion stack: In the worst case (for a skewed tree), the recursion depth is O(n). For a balanced binary tree, it is O(log n).
  2. Temporary vectors (`left` and `right`) created at each level: The total size of these vectors is proportional to the number of nodes, O(n).
- Total space complexity: O(n) (dominant factor is the size of the `temp` vector).

*/
