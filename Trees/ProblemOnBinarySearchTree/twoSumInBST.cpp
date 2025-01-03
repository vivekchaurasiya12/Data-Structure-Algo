#include <iostream>
#include <stack>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// BSTIterator class definition
class BSTIterator {
    stack<TreeNode*> st; // Stack to store tree nodes
    bool reverse;        // Determines the traversal direction (true for reverse)

public:
    // Constructor initializes the iterator with the root and traversal direction
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse; // Set traversal direction
        pushAll(root);       // Push initial nodes onto the stack
    }

    // Returns the next element in the desired order
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        // Push appropriate subtree based on traversal direction
        if (!reverse)
            pushAll(tempNode->right);
        else
            pushAll(tempNode->left);
        return tempNode->val;
    }

private:
    // Push all nodes along the traversal path onto the stack
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            // Traverse in the appropriate direction
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

// Solution class to solve the "Two Sum in BST" problem
class Solution {
public:
    bool twoSum(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        // Create two iterators: one for in-order traversal and one for reverse in-order
        BSTIterator l(root, false); // Left-to-right traversal
        BSTIterator r(root, true);  // Right-to-left traversal

        int i = l.next(); // Smallest element
        int j = r.next(); // Largest element

        // Use the two-pointer technique
        while (i < j) {
            if (i + j == k) // If the sum matches the target, return true
                return true;
            else if (i + j < k) // If the sum is less, move to the next larger element
                i = l.next();
            else // If the sum is greater, move to the next smaller element
                j = r.next();
        }

        return false; // If no pair is found, return false
    }
};

// Test the solution
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Define the target sum
    int target = 9;

    // Initialize the solution and find if the target sum exists
    Solution solution;
    bool result = solution.twoSum(root, target);

    // Output the result
    if (result)
        cout << "Target " << target << " exists as the sum of two elements in the BST." << endl;
    else
        cout << "Target " << target << " does not exist in the BST." << endl;

    return 0;
}
