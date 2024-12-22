#include <bits/stdc++.h> // Includes all standard headers in C++ (not recommended for production, use specific headers instead)
using namespace std;

// Structure definition for a tree node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value and set left and right pointers to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative function to perform preorder traversal of the binary tree
vector<int> preOrderTraversal(Node* root) {
    vector<int> temp; // Vector to store traversal results
    if (root == NULL) {
        return temp;  // If the root is null, return an empty vector
    }

    stack<Node*> st;  // Stack to store nodes for processing
    st.push(root);    // Start with the root node

    while (!st.empty()) {
        Node* current = st.top(); // Get the top node from the stack
        st.pop();                 // Remove it from the stack
        temp.push_back(current->data); // Visit the current node

        // Push the right child first (if it exists)
        if (current->right != NULL) {
            st.push(current->right);
        }

        // Push the left child next (if it exists)
        if (current->left != NULL) {
            st.push(current->left);
        }
    }

    return temp; // Return the result vector
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

3. **Iterative Approach**:
   - A stack is used to replace the recursion stack.
   - The root node is pushed onto the stack first.
   - Nodes are processed in the following sequence:
     1. Pop the top node from the stack.
     2. Visit the node (store its value in the result vector).
     3. Push its right child (if not `NULL`) onto the stack.
     4. Push its left child (if not `NULL`) onto the stack.
   - This ensures the left child is processed before the right child, maintaining the preorder sequence.

4. **Edge Cases**:
   - If the root is `NULL`, the function immediately returns an empty vector.

5. **Memory Allocation**:
   - Tree nodes are dynamically allocated using `new`. In real-world applications, ensure proper deletion of nodes to avoid memory leaks.

*/

 /*
TIME COMPLEXITY:
- Each node is visited exactly once, and each node's children are pushed onto the stack once.
- For a tree with `n` nodes, the time complexity is O(n).

SPACE COMPLEXITY:
- The space complexity is determined by the size of the stack:
  1. In the worst case (a completely unbalanced tree), the stack can hold all `n` nodes simultaneously, making space complexity O(n).
  2. In the best case (a balanced binary tree), the stack holds nodes proportional to the height of the tree, which is O(log n).
- The result vector uses O(n) space to store the traversal results.
- Overall space complexity: O(n).

*/
