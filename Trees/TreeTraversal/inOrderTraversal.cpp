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

// Function to perform inorder traversal of the binary tree
vector<int> inOrderTraversal(Node* root) {
    vector<int> temp; // Vector to store traversal results
    if (root == NULL) {
        return temp;  // If the node is null, return an empty vector
    }

    // Recur for the left subtree
    vector<int> left = inOrderTraversal(root->left);
    temp.insert(temp.end(), left.begin(), left.end());

    // Visit the current node (root)
    temp.push_back(root->data);

    // Recur for the right subtree
    vector<int> right = inOrderTraversal(root->right);
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

    // Perform inorder traversal
    vector<int> result = inOrderTraversal(root);

    // Print the traversal result
    for (const auto& it : result) {
        cout << it << " ";
    }

    return 0;
}

/*
IMPORTANT NOTES:

1. **Tree Node Structure**:
   - The `Node` structure has `data`, `left`, and `right` members to define the binary tree.
   - A constructor initializes the node with a value and sets child pointers to `nullptr`.

2. **Inorder Traversal**:
   - Inorder traversal visits nodes in this order:
     1. Traverse the left subtree.
     2. Visit the root.
     3. Traverse the right subtree.
   - The result vector `temp` collects the nodes' data in this order.

3. **Base Case in Recursion**:
   - If `root` is `NULL`, an empty vector is returned, ensuring recursion terminates.

4. **Recursive Calls**:
   - The function recurs on the left and right subtrees.
   - Results from the left subtree are appended first, followed by the root's data and then the right subtree's results.

5. **Memory Allocation**:
   - Tree nodes are dynamically allocated using `new`.
   - In a real-world application, ensure proper memory deallocation to avoid memory leaks.

6. **Code Quality**:
   - Instead of using the `<bits/stdc++.h>` header, include specific headers like `<vector>` and `<iostream>` for better compilation times and portability.

*/

/*
TIME COMPLEXITY:
- The function visits each node exactly once.
- For a tree with `n` nodes, the time complexity is O(n).

SPACE COMPLEXITY:
- Space is used for:
  1. Recursion stack: In the worst case (for a skewed tree), the recursion depth is O(n). For a balanced binary tree, it is O(log n).
  2. Temporary vectors (`left` and `right`) created at each level: The combined size is proportional to the number of nodes, O(n).
- Total space complexity: O(n) (dominant factor is the size of the result vector).

*/
